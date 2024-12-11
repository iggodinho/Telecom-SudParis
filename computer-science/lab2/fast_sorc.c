#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SAMPLES 5

// Swap utility function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quicksort function
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Heapify function for Heap Sort
void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapsort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to fill an array with random numbers
void fill_random(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to fill an array in reverse order
void fill_reverse(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = length - i;
    }
}

// Function to measure sorting time
void measure_sorting_time(void (*sort_func)(int *, int), int *arr, int length, const char *sort_name) {
    clock_t start, end;
    double total_time = 0;

    for (int i = 0; i < NUM_SAMPLES; i++) {
        fill_random(arr, length);
        start = clock();
        sort_func(arr, length);
        end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    printf("%s (random): Average time for %d elements: %.6f seconds\n", sort_name, length, total_time / NUM_SAMPLES);

    total_time = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        fill_reverse(arr, length);
        start = clock();
        sort_func(arr, length);
        end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }
    printf("%s (reverse): Average time for %d elements: %.6f seconds\n", sort_name, length, total_time / NUM_SAMPLES);
}

// Wrapper function for quicksort
void quicksort_wrapper(int *arr, int length) {
    quicksort(arr, 0, length - 1);
}

int main() {
    srand(time(NULL));
    int lengths[] = {101, 102, 103, 104, 105};
    int *arr;

    for (int i = 0; i < sizeof(lengths) / sizeof(lengths[0]); i++) {
        int length = lengths[i];
        arr = malloc(length * sizeof(int));
        if (!arr) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        printf("\nTesting with array length: %d\n", length);
        measure_sorting_time(quicksort_wrapper, arr, length, "Quicksort");
        measure_sorting_time(heapsort, arr, length, "Heap Sort");

        free(arr);
    }

    return 0;
}
