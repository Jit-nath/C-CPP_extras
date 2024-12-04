#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in the array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on a specific digit
void countingSort(int arr[], int size, int place) {
    int *output = (int *)malloc(size * sizeof(int)); // Output array
    int count[10] = {0};                             // Count array for digits 0-9

    // Store count of occurrences in count[]
    for (int i = 0; i < size; i++) {
        count[(arr[i] / place) % 10]++;
    }

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    free(output); // Free dynamically allocated memory
}

// Radix Sort function
void radixSort(int arr[], int size) {
    // Find the maximum number to know the number of digits
    int max = findMax(arr, size);

    // Do counting sort for every digit. The place is 10^i where i is the current digit number
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, size, place);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    radixSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
