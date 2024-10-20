// by Sean Stepanik 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(vector<int> &v, int n)  
{  
    int i, j, min;  
    for (i = 0; i < n-1; i++)  
    {
        min = i;  
        for (j = i+1; j < n; j++) {if (v[j] < v[min]) {min = j;}}
        swap(&v[min], &v[i]);   
    }  
}  

void print(vector<int> v)
{
    for (int val : v)
        std::cout << val << " ";
    std::cout << "\n";
}

void fillByRandomNums(vector<int> &v){
    // Generate n random numbers between 0 and 99 by lambda func and fill it in vector
    std::generate(v.begin(), v.end(), []() { return rand() % 100;});
}
  
int main()  
{  
    int n;
    std::cout << "Enter the number of integers" << endl;
    cin >> n;

    std::vector<int> v(n);
    fillByRandomNums(v);
    std::cout << "Random\n";
    print(v);
    selectionSort(v, n);
    std::cout << "Sorted\n" ;
    print(v);
   
    return 0;
}  
