#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void print2DArray(int **arr, int n)
{
    for (int i = 1; i < n; i++){ //start from 1
        for (int j = 1; j < n; j++) //start from 1
            cout << arr[i][j] << " ";
        cout << "\n";
    }

}

void matrixChainMultiplication(int *p, int **m, int **s, int n)
{
    int i, j, k, L, q;

    /* m[i, j] = Minimum number of multiplications needed
    to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q =  multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }//if
            }// for k
        }//for i
    }//for L
//cout << "Minimum number of multiplications is " + m[1][n - 1];
/*    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }*/
}

void printOptParens(int **s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
         cout << "(";
        printOptParens(s, i, s[i][j]);
        printOptParens(s, s[i][j]+1, j);
        cout << ")";
    }
}

int main()
{   int p[] = {30, 35, 15, 5, 10, 20, 25};
    //int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p)/sizeof(p[0]);

    int **m; //result, 2D array
    m = new int *[n]; //memory allocation to m
    for(int i = 0; i <n; i++)
        m[i] = new int[n];
    for (int i = 0; i< n; i++)//initilize m
        for (int j = 0; j < n; j++)
           m[i][j] = 0;

    int **s;//path, 2D array
    s = new int *[n]; //memory allocation to s
    for(int i = 0; i <n; i++)
        s[i] = new int[n];
    for (int i = 0; i< n; i++)
        for (int j = 0; j < n; j++)
           s[i][j] = 0;

    matrixChainMultiplication(p, m, s, n);
    cout << "Minimum number of multiplications is " << m[1][n - 1] << "\n";
    printOptParens(s, 1, n-1);
    cout << "\n";;

    //print m and s
    cout << "--------------m------------------" << "\n";
    print2DArray(m, n);
    cout << "--------------s------------------" << "\n";
    print2DArray(s, n);



    return 1;
}
