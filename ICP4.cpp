#include <iostream>
using namespace std;

// Function to perform linear search recursively
int linearSearch(int arr[], int size, int key, int index = 0) {
    if (index == size) {return -1;}

    if (arr[index] == key) {return index;}

    return linearSearch(arr, size, key, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    std::cout << "Enter the searched number " << endl;
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
