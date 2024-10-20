#include<limits> // for limit
#include<cmath>  // for floor()
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void printVector(vector<int> v); //function prototype

void merge(vector<int> &A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int limit = numeric_limits<int>::max();
    int i, j, k;

    std::vector<int> L(n1+1);
    for (i = 0; i < n1; i++)
        L[i] = A[p+i]; // Range in A: [p, p+(n1-1)]
    L[n1] = limit;

    std::vector<int> R(n2+1);
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j]; // Range in A: [(q+1), (q+1)+(n2-1)]
    R[n2] = limit;

    i = 0;
    j = 0;

    for (k = p; k <= r; k++)
    {
        if (L[i] < R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
 }

void fillByRandomNums(vector<int> &v){
    // Generate 10 random numbers between 0 and 99 by lambda func and fill it in vector
    std::generate(v.begin(), v.end(), []() {
        return rand() % 100;
    });
}

// A utility function to print an array of size n
void printVector(vector<int> v)
{
    for (int val : v)
        std::cout<< val << std::endl;
}

void mergeSort(std::vector<int> &A, int p, int r){
    if (p < r){
        int q = floor((p + r)/2);
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }

}

/* Driver code */
int main()
{
    int n;
    std::cout << "Enter the number of integers" << endl;
    cin >> n;
    std::vector<int> v(n);

    fillByRandomNums(v);

    std::cout << "Original Array: " << "\n";
    printVector(v);

    mergeSort(v, 0, n-1);
    std::cout << "Sorted Array: " << "\n";
    printVector(v);

    return 0;
}


