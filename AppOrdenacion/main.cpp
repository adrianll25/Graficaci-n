//Jesus Adrian Lopez Luevanos
//#18131253
//Graficación
//AppOedenacion

#include <iostream>
#include <time.h>

using namespace std;

//Metodo Insercion Ascendente
void InsercionAscendente ( int arr[], int n )
{
    int i;
    int key;
    int j;

    for ( i = 1; i < n; i++ )
    {
        key = arr[i];
        j = i - 1;

        while ( j >= 0 && arr[j] > key )
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Metodo Insercion Descendente
void InsercionDescendente ( int arr[], int n )
{
    int i;
    int key;
    int j;

    for ( i = 1; i < n; i++ )
    {
        key = arr[i];
        j = i - 1;


        while ( j >= 0 && arr[j] < key )
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Metodo Burbuja Ascendente
void BurbujaAscendente ( int arr[], int n )
{
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = n - 1; j > i; j-- )
        {
            if ( arr[j-1] > arr[j] )
            {
                int aux = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

//Metodo Burbuja Descendente
void BurbujaDescendente ( int arr[], int n )
{
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = n - 1; j > i; j-- )
        {
            if ( arr[j-1] < arr[j] )
            {
                int aux = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

//Metodo Quick Ascendente
void quickAscendente ( int Arr[],int izq, int der )
{
    int i;
    int j;
    int x;
    int aux;
    i = izq;
    j = der;
    x = Arr[ (izq + der) / 2 ];

    do
    {
        while ( (Arr[i] < x) && (j <= der) )
        {
            i++;
        }

        while ( (x < Arr[j]) && (j > izq) )
        {
            j--;
        }

        if ( i <= j )
        {
            aux = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = aux;

            i++;  j--;
        }
    }
    while ( i <= j );

    if ( izq < j )
    {
        quickAscendente( Arr, izq, j );
    }
    if ( i < der )
    {
        quickAscendente( Arr, i, der );
    }
}

//Metodo Quick Descendente
void quickDescendente ( int Arr[],int izq, int der )
{
    int i;
    int j;
    int x;
    int aux;

    i = izq;
    j = der;
    x = Arr[ (izq + der) / 2 ];

    do
    {
        while ( (Arr[i] > x) && (j <= der) )
        {
            i++;
        }

        while ( (x > Arr[j]) && (j > izq) )
        {
            j--;
        }

        if ( i <= j )
        {
            aux = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = aux;

            i++;  j--;
        }
    }
    while ( i <= j );

    if ( izq < j )
    {
        quickDescendente ( Arr, izq, j );
    }
    if ( i < der )
    {
        quickDescendente ( Arr, i, der );
    }
}


