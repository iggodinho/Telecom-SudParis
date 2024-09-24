#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int is_sorted(int *array, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            return 0;  // Return 0 (false) if the array is not sorted
        }
    }
    return 1;  // Return 1 (true) if the array is sorted
}

void bubble_sort(int *array, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        for (unsigned int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    /*if (!is_sorted(array, length)) {
        printf("Bubble Sort - Array is NOT sorted!\n");
    }*/ //uncomment for debugging
}

void insertion_sort(int *array, unsigned int length) {
    for (unsigned int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    /*if (!is_sorted(array, length)) {
        printf("Insertion Sort - Array is NOT sorted!\n");
    }*/ //uncomment for debugging
}

void selection_sort(int *array, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        unsigned int min_index = i;
        for (unsigned int j = i + 1; j < length; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
    /*if (!is_sorted(array, length)) {
        printf("Selection Sort - Array is NOT sorted!\n");
    }*/ //uncomment for debugging
}

void rand_fill(int *array, unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        array[i] = rand() % 100;  
    }
}

void reverse_fill(int *array, unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        array[i] = length - i - 1;  // Fill in reverse order
    }
}

double time_sort(void (*sort_func)(int*, unsigned int), int *array, unsigned int length) {
    clock_t start, end;
    start = clock();
    sort_func(array, length);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;  // Return time in seconds
}

void test_sorts(unsigned int length) {
    FILE *file = fopen("sort_results.txt", "w");  // overwrite text file
    if (file == NULL) {
        printf("Error when opening the file!\n");
        exit(1);
    }

    int *array = (int *)malloc(length * sizeof(int));  // Allocate memory for the array
    int *copy = (int *)malloc(length * sizeof(int));   // Allocate memory for a copy of the array

    if (array == NULL || copy == NULL) {
        printf("Memory allocation failed!\n");
        fprintf(file, "Memory allocation failed!\n");
        fclose(file);
        exit(1);
    }

    double avg_time_bubble_rand = 0, avg_time_insertion_rand = 0, avg_time_selection_rand = 0;
    double avg_time_bubble_reverse = 0, avg_time_insertion_reverse = 0, avg_time_selection_reverse = 0;

    for (int i = 0; i < 5; i++) {  // Perform 5 samples for each sorting algorithm

        // Test on random data
        rand_fill(array, length);
        memcpy(copy, array, length * sizeof(int));  // Copy the original array
        avg_time_bubble_rand += time_sort(bubble_sort, copy, length);

        memcpy(copy, array, length * sizeof(int));  // Reset the copy
        avg_time_insertion_rand += time_sort(insertion_sort, copy, length);

        memcpy(copy, array, length * sizeof(int));  // Reset the copy
        avg_time_selection_rand += time_sort(selection_sort, copy, length);

        // Test on reverse sorted data
        reverse_fill(array, length);
        memcpy(copy, array, length * sizeof(int));  // Copy the reverse array

        avg_time_bubble_reverse += time_sort(bubble_sort, copy, length);

        memcpy(copy, array, length * sizeof(int));  // Reset the copy
        avg_time_insertion_reverse += time_sort(insertion_sort, copy, length);

        memcpy(copy, array, length * sizeof(int));  // Reset the copy
        avg_time_selection_reverse += time_sort(selection_sort, copy, length);
    }

    fprintf(file, "Array size: %u\n", length);
    fprintf(file, "Average time for Bubble Sort (random): %.6f seconds\n", avg_time_bubble_rand / 5);
    fprintf(file, "Average time for Insertion Sort (random): %.6f seconds\n", avg_time_insertion_rand / 5);
    fprintf(file, "Average time for Selection Sort (random): %.6f seconds\n", avg_time_selection_rand / 5);
    fprintf(file, "Average time for Bubble Sort (reverse): %.6f seconds\n", avg_time_bubble_reverse / 5);
    fprintf(file, "Average time for Insertion Sort (reverse): %.6f seconds\n", avg_time_insertion_reverse / 5);
    fprintf(file, "Average time for Selection Sort (reverse): %.6f seconds\n", avg_time_selection_reverse / 5);
    fprintf(file, "\n");

    free(array);  // Deallocate memory
    free(copy);   // Deallocate memory
    fclose(file); 
}

int main() {
    srand(time(NULL));  // Seed random number generator

    // Testing the sorting algorithms with different array sizes
    unsigned int sizes[] = {10, 100, 1000, 10000, 30000};
    for (int i = 0; i < 5; i++) {
        test_sorts(sizes[i]);
    }

    return 0;
}