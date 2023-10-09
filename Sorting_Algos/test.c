#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_algorithms.h"

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Define the size of the array
    int size = 10;

    // Create an array of random integers
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};

    printf("Original array: ");
    printArray(arr, size);

    // Test Bubble Sort
    bubbleSort(arr, size);
    printf("Bubble Sort: ");
    printArray(arr, size);

    // Test Selection Sort
    int arr2[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    selectionSort(arr2, size);
    printf("Selection Sort: ");
    printArray(arr2, size);

    // Test Insertion Sort
    int arr3[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    insertionSort(arr3, size);
    printf("Insertion Sort: ");
    printArray(arr3, size);

    // Test Merge Sort
    int arr4[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    mergeSort(arr4, 0, size - 1);
    printf("Merge Sort: ");
    printArray(arr4, size);

    // Test Quick Sort
    int arr5[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    quickSort(arr5, 0, size - 1);
    printf("Quick Sort: ");
    printArray(arr5, size);

    // Test Radix Sort
    int arr6[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    radixSort(arr6, size6);
    printf("Radix Sort: ");
    printArray(arr6, size6);

    // Test Heap Sort
    int arr7[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 50};
    heapSort(arr7, size);
    printf("Heap Sort: ");
    printArray(arr7, size);

    return 0;
}
