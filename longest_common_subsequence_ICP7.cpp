//Sean Stepanik
#include<iostream>
#include<string>  
#include<utility> 
using namespace std;

typedef pair<int, char> pairs;

void LCS(string X, string Y, pairs **c, int m, int n) {
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0) {
                c[i][j].first = 0;
                c[i][j].second = ' ';
            }
            else {
                if (X[i-1]==Y[j-1]) {
                    c[i][j].first = c[i-1][j-1].first + 1;
                    c[i][j].second = 'd';
                }
                else if ((c[i-1][j].first > c[i][j-1].first) || (c[i-1][j].first == c[i][j-1].first)) {
                    c[i][j].first = c[i-1][j].first;
                    c[i][j].second = 'u';
                }
                else {
                    c[i][j].first = c[i][j-1].first;
                    c[i][j].second = 'l';
                }
            }
        }
    }

}

void printC(pairs **c, int m, int n) {
    for (int i = 0; i< m+1; i++) {
        for (int j = 0; j < n+1; j++) cout << c[i][j].first << c[i][j].second << " ";
        cout << "\n";
    }
}

void printLCS(pairs **c, string X, int i, int j) {
    if ((i==0) || (j==0)) return;
    if (c[i][j].second == 'd') {
        printLCS(c, X, i-1, j-1);
        cout << X[i-1];//X starts at index 0
    }
    else if (c[i][j].second == 'u') printLCS(c, X, i-1, j);
    else printLCS(c, X, i, j-1);
}

int main() {
    string X  = "ABCBDAB";
    string Y = "BDCABA";
    int m = X.length();
    int n = Y.length();

    pairs **c; //result, 2D array
    c = new pairs *[m+1]; //memory allocation to m
    for(int i = 0; i <m+1; i++) c[i] = new pairs[n+1];

    LCS(X, Y, c, m, n);

    cout << "Table C" << "\n\n";
    printC(c, m, n);
    cout << "\nThe Longest Common Subsequence is: ";
    printLCS(c, X, m, n);
}
