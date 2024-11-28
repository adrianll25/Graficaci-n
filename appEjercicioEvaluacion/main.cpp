/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// EVALUACION: REALIZAR UNA PRUEBA DE ESCRITORIO LA APP.
// MUESTRE SU FUNCIONAMIENTO
// INDIQUE QUE TAREA RESUELVE
// DOCUMENTE LOS METODOS

#include <iostream>
#include <time.h>
using namespace std;
const int n = 500;

//void insercion(int arr[], int n)
void insercion(int *arr, int n)
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


void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    //int arr[] = { 12, 11, 13, 5, 6 };
    //int n = sizeof(arr) / sizeof(arr[0]);

    int *vec = new int[n];
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        vec[i] = rand();

    }

    printArray(vec, n);
    insercion(vec, n);
    printArray(vec, n);

    return 0;
}




// This is code is contributed by rathbhupendra

