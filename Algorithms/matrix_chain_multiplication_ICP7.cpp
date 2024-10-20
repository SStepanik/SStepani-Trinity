//by Sean Stepanik
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void print2DArray(int **arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}

void matrixChainMultiplication(int *p, int **m, int **s, int n) {
    int i, j, k, C, q;

    for (i = 1; i < n; i++) m[i][i] = 0;

    // C is chain length
    for (C = 2; C < n; C++) {
        for (i = 1; i < n - C + 1; i++) {
            j = i + C - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                // q =  multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptParens(int **s, int i, int j) {
    if (i == j) cout << "A" << i;
    else {
        cout << "(";
        printOptParens(s, i, s[i][j]);
        printOptParens(s, s[i][j]+1, j);
        cout << ")";
    }
}

int main() {   
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p)/sizeof(p[0]);

    int **m;
    m = new int *[n];
    for(int i = 0; i <n; i++) m[i] = new int[n];
    for (int i = 0; i< n; i++) {
        for (int j = 0; j < n; j++) m[i][j] = 0;
    }

    int **s;
    s = new int *[n];
    for(int i = 0; i <n; i++) s[i] = new int[n];
    for (int i = 0; i< n; i++) {
        for (int j = 0; j < n; j++) s[i][j] = 0;
    }

    matrixChainMultiplication(p, m, s, n);
    cout << "Minimum number of multiplications is " << m[1][n - 1] << "\n";
    printOptParens(s, 1, n-1);
    cout << "\n";
    cout << "--------------m------------------" << "\n";
    print2DArray(m, n);
    cout << "--------------s------------------" << "\n";
    print2DArray(s, n);

    return 1;
}