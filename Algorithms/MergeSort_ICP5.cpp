//Sean Stepanik
#include<limits> 
#include<cmath>  
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void printV(vector<int> v){
    for (int val : v) {
        std::cout << val << " "; 
    }
    std::cout << "\n";
}

void fillRand(vector<int> &v){
    std::generate(v.begin(), v.end(), []() { return rand() % 100;});
}

void merge(vector<int> &A, int p, int q, int r) {
    int n_1 = q - p + 1;
    int n_2 = r - q;
    int limit = numeric_limits<int>::max();
    int i;
    int j;
    int k;

    std::vector<int> Left(n_1+1);
    for (i = 0; i < n_1; i++) {
        Left[i] = A[p+i];
    }
    Left[n_1] = limit;

    std::vector<int> Right(n_2+1);
    for (j = 0; j < n_2; j++) {
        Right[j] = A[q + 1 + j];
    }
    Right[n_2] = limit;

    i = 0;
    j = 0;

    for (k = p; k <= r; k++) {
        if (Left[i] < Right[j]) {
            A[k] = Left[i];
            i++;
        }
        else {
            A[k] = Right[j];
            j++;
        }
    }
}

void sort(std::vector<int> &A, int p, int r){
    if (p < r){
        int q = floor((p + r)/2);
        sort(A, p, q);
        sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int n;
    std::cout << "Enter the number of integers" << endl;
    cin >> n;
    std::vector<int> v(n);

    fillRand(v);

    std::cout << "Original Array: " << endl;
    printV(v);

    mergeSort(v, 0, n-1);
    std::cout << "Sorted Array: " << endl;
    printV(v);

    return 0;
}