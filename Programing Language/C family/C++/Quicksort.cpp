#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Function to partition the array around the pivot
int partition(std::vector<int>& arr, int low, int high) {
    // 1. Choose the pivot (here, we choose the rightmost element)
    int pivot = arr[high];
    
    // Index of the smaller element and indicates the correct position of the pivot found so far
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    // Place the pivot element in its correct sorted position
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Main Quicksort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print the array
void printArray(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// Driver code to test the implementation
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5, 20, 2};
    int n = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
