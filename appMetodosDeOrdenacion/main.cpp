#include <iostream>
#include <time.h>

using namespace std;

//Metodo Insercion de manera Ascendente
void insercionAscendente(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Metodo Insercion de manera Descendente
void insercionDescendente(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Metodo Burbuja de manera Ascendente
void burbujaAscendente(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(arr[j-1] > arr[j])
            {
                int aux = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

//Metodo Burbuja de manera Descendente
void burbujaDescendente(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(arr[j-1] < arr[j])
            {
                int aux = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

//Metodo Quick de manera Ascendente
void quickAscendente(int Arr[],int izq, int der )
{
    int i, j, x , aux;
    i = izq;
    j = der;
    x = Arr[ (izq + der) / 2 ];

    do
    {
        while( (Arr[i] < x) && (j <= der) )
        {
            i++;
        }

        while( (x < Arr[j]) && (j > izq) )
        {
            j--;
        }

        if( i <= j )
        {
            aux = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = aux;

            i++;  j--;
        }
    }
    while( i <= j );

    if( izq < j )
    {
        quickAscendente( Arr, izq, j );
    }
    if( i < der )
    {
        quickAscendente( Arr, i, der );
    }
}

//Metodo Quick de manera Descendente
void quickDescendente(int Arr[],int izq, int der )
{
    int i, j, x , aux;
    i = izq;
    j = der;
    x = Arr[ (izq + der) / 2 ];

    do
    {
        while( (Arr[i] > x) && (j <= der) )
        {
            i++;
        }

        while( (x > Arr[j]) && (j > izq) )
        {
            j--;
        }

        if( i <= j )
        {
            aux = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = aux;

            i++;  j--;
        }
    }
    while( i <= j );

    if( izq < j )
    {
        quickDescendente( Arr, izq, j );
    }
    if( i < der )
    {
        quickDescendente( Arr, i, der );
    }
}

//Metodo para mostrar el arreglo
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Main principal
int main()
{
    //La funcion time devuelve el numero de segundos transcurridos desde las 0 horas del 1 de enero de 1970
    srand(time(nullptr));

    int n;

    //Solicitar al usuario los datos
    cout<<"Numeros de elementos: "<<endl;
    cin>>n;

    //Creacion arreglo
    int *arr = new int [n];

    //Llenar el arreglo con datos aleatorios
    for(int i = 0; i < n; i++)
    {
        int dato = (int)rand()%900+100;
        arr[i] = dato;
    }

    cout<<"Datos Generados: ";
    printArray(arr, n);
    cout<<"----------------------------------------------------------\n";

    cout<<"Insercion Ascendente: "<<endl;
    insercionAscendente(arr, n);
    printArray(arr, n);

    cout<<"\n";

    cout<<"Insercion Descendente: "<<endl;
    insercionDescendente(arr, n);
    printArray(arr, n);

    cout<<"-------------------------------------------\n";

    cout<<"Burbuja Ascendente: "<<endl;
    burbujaAscendente(arr, n);
    printArray(arr, n);

    cout<<"\n";

    cout<<"Burbuja Descendente: "<<endl;
    burbujaDescendente(arr, n);
    printArray(arr, n);

    cout<<"-------------------------------------------\n";

    cout<<"Quick Ascendente: "<<endl;
    quickAscendente(arr, 0 ,n-1);
    printArray(arr, n);

    cout<<"\n";

    cout<<"Quick Descendente: "<<endl;
    quickDescendente(arr, 0 , n-1);
    printArray(arr, n);
    cout<<"-------------------------------------------"<<endl;

    return 0;
}
