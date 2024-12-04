#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort function
void countingSort(int arr[], int size) {
    // Find the maximum value in the array
    int max = findMax(arr, size);

    // Create a count array and initialize it to 0
    int *count = (int *)calloc(max + 1, sizeof(int));
    if (!count) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Count the occurrences of each element
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Update the input array based on count array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Free the dynamically allocated memory
    free(count);
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    countingSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
