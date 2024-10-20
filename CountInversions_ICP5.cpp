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

int merge(vector<int> &A, int p, int q, int r) {
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

    int inversions = 0;
    for (k = p; k <= r; k++) {
        if (Right[j] < Left[i]) {
            if (i != n_1){
                inversions += n_1 - i;
                A[k] = Right[j];
                j++;
            }
        } else {
            A[k] = Left[i];
            i++;
        }
    }
    return inversions;
}

int sort(std::vector<int> &A, int p, int r) {
    int left;
    int right;
    int merge;
    if (p == r) {return 0;}
    else if (p < r){
        int q = floor((p + r)/2);
        left = sort(A, p, q);
        right = sort(A, q+1, r);
        merge = merge(A, p, q, r);
    }

    return (left + right + merge);
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

    int count =  sort_Count(v, 0, n-1);;

    std::cout << "Sorted Array: " << endl;
    printV(v);
    std::cout << "Inversions = " << count << endl;

    return 0;
}