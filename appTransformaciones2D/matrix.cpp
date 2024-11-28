#include "matrix.h"
#include <math.h>
#include <assert.h>

Matrix::Matrix(int nr,int nc, float valor)
{
  ren = nr;
  col = nc;
  Mat = new float*[ren]; //Se crea el vector de punteros

  assert(Mat);//Si NEW asigna null el programa se debe abortar.

  for(int i = 0; i < ren; i++)
  {
      Mat[i] = new float[col]; //Asignar memoria por renglon, es decir para cada columna
      assert(Mat[i]);
  }

  for(int i = 0; i < ren; i++)
    for(int j = 0; j < col; j++)
        Mat[i][j] = valor;
}

Matrix::Matrix(float nr,float nc, float **m)
{
  ren = nr;
  col = nc;
  Mat = new float*[ren];

  assert(Mat);

  for(int i = 0; i < ren; i++)
  {
      Mat[i] = new float[col];
      assert(Mat[i]);
  }

  for(int i = 0; i < ren; i++)
    for(int j = 0; j < col; j++)
        Mat[i][j] = m[i][j];
}


//CONSTRUCTOR DE COPIA

Matrix::Matrix(Matrix &m)
{
   this->ren = m.numRen();
   col = m.numCol();
   Mat =new float*[ren];

   for(int i = 0; i < ren; i++)
  {
     Mat[i] = new float[col];
     assert(Mat[i]);
  }

   for(int i=0; i<ren; i++)
      for( int j=0; j<col; j++)
         Mat[i][j]=m.GET(i,j);
}

void Matrix::Inicializa(int R, int C)
{
   col=C;
   ren=R;
   Mat=new float *[ren];

   for(int i=0; i<ren; i++)
      Mat[i]=new float[col];

   for(int i=0; i<ren; i++)
      for(int j=0; j<col; j++)
         Mat[i][j]=0;
}

Matrix &Matrix::operator*=(Matrix &mat2)
{
   Matrix aux;//Se puede llamar al constructor
   aux.Inicializa(this->ren, mat2.numCol());


   for(int i = 0; i < ren; i++)
   {
      for(int j = 0; j < mat2.numCol(); j++)
      {
         float suma = 0;
         for(int k = 0; k < col; k++)
         {
           //suma += floor(Mat[i][k]*mat2.GET(k,j)+0.5);
           suma += round(Mat[i][k]*mat2.GET(k,j));
           aux.SET(i,j,suma);
         }
         //aux.SET(i,j,suma);
      }
   }
   asignar(aux);
   return *this;
}

Matrix Matrix::operator*(float val)
{
   Matrix temp;
   temp.Inicializa(ren,col);
   for(int i=0; i<ren;i++)
      for(int j=0; j<col; j++)
         temp.SET(i,j,Mat[i][j]* val);
   return temp;
}


Matrix &Matrix::operator*(const Matrix &m1)
{
  //assert((ren == m1.ren) && (col == m1.col));
   Matrix * result = new Matrix(ren,col,0);
   assert(result);
   for(int i = 0; i < ren; i++)
   {
        for(int j = 0;  j < col; j++)
        {
            //DEBE SER EL NUMERO DE COLUMNAS
            //REN SOLO SI ES CUADRADA EJ: 3 x 3
            for(int k = 0; k < col; k++)
            {
                //result->Mat[i][j]= result->Mat[i][j] + Mat[i][k] * m1.Mat[k][j];
                result->Mat[i][j] += Mat[i][k] * m1.Mat[k][j];
            }
        }
    }

   return *result;
}

Matrix &Matrix::operator=(Matrix &m)
{
//eliminar el tamaño de la matriz destino
  for(int i= 0; i < ren;i++ )
     //Se borran los renglones de la matriz
       delete [] Mat[i];

  //Se borra el arreglo de punteros
  delete []Mat;

//Asignar los nuevos datos de la matriz que llego
  ren = m.numRen();
  col = m.numCol();
  Mat = new float * [ren];
  assert(Mat);

  for(int i = 0; i < ren; i++)
  {
     Mat[i] = new float[col];
     assert(Mat[i]);
  }

  for( int i =0; i < ren; i++)
  {
    for(int j = 0; j < col; j++)
    {
        Mat[i][j] = m.Mat[i][j];
    }
  }

  return *this;
}


Matrix &Matrix::asignar(Matrix m)
{
   for(int i=0;i<m.numRen();i++)
   {
       for(int j=0;j<m.numCol();j++)
       {
                Mat[i][j]=m.GET(i,j);
       }
   }
   return *this;
}

Matrix::~Matrix()
{
  //Se libera la memoria
  for(int i= 0; i<ren;i++ )
     //Se borran los renglones de la matriz
       delete [] Mat[i];

  //Se borra el arreglo de punteros
  delete []Mat;

}

Matrix &Matrix::Identidad()
{
  for(int i = 0; i < ren; i++)
  {
    for( int j = 0; j < col; j++)
    {
      if( i == j)
      {
         Mat[i][i]= 1;
      }
      else
      {
         Mat[i][j]= 0;
      }
    }
  }
  return *this;
}

//             TRANSFORMACIONES 2D
Matrix &Matrix::traslacion(Matrix fig, Matrix identidad, int tx, int ty)
{
    identidad.Identidad();
    identidad.SET(2, 0, tx);//SE CREO LA MATRIZ DE TRANSLACION 2D
    identidad.SET(2,1,ty);

    fig *= identidad;
    this->asignar(fig);
    return *this;

}

Matrix &Matrix::escalacion(Matrix fig, Matrix identidad, float sx, float sy)
{
   identidad.Identidad();
   identidad.SET(0,0,sx);
   identidad.SET(1,1,sy);

   fig *= identidad;
   asignar(fig);
   return *this;
}

Matrix &Matrix::escalacionPuntoFijo(Matrix f, Matrix id, float sx, float sy, int PFx, int PFy)
{
    id.Identidad();
    float escPFx = PFx * (1-sx);
    float escPFy = PFy * (1-sy);

    id.SET(0,0,sx);
    id.SET(1,1,sy);
    id.SET(2,0,escPFx);
    id.SET(2,1,escPFy);
    f*=id;
    asignar(f);
    return *(this);

}

Matrix &Matrix::rotacion(Matrix f, Matrix id, double ang)
{
    id.Identidad();

    ang = ang * 3.141592 / 180;

    double coseno = cos(ang);
    double seno = sin(ang);

    id.SET(0,0, coseno);
    id.SET(1,1, coseno);
    id.SET(0,1, seno);
    id.SET(1,0, -seno);

    f *= id;

    asignar(f);

    return *this;
}


