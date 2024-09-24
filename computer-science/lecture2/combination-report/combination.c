#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the current combination
void printCombination(int comb[], int k) {
    for (int i = 0; i < k; i++) {
        printf("%d ", comb[i]);
    }
    printf("\n");
}

// Function to generate the next combination
int nextCombination(int comb[], int n, int k) {
    int i = k - 1;

    // Find the rightmost element that can be incremented
    while (i >= 0 && comb[i] == n - k + i + 1) {
        i--;
    }

    // If all elements are in their maximum position, return 0 to signal end
    if (i < 0) {
        return 0;
    }

    // Increment this element
    comb[i]++;

    // Set all subsequent elements to the smallest possible value
    for (int j = i + 1; j < k; j++) {
        comb[j] = comb[j - 1] + 1;
    }

    return 1; // Return 1 to signal that the next combination was generated
}

int main() {
    int n_values[] = {10, 25, 50}; // Array of n values to test
    int k_values[] = {3, 5, 9};    // Array of k values to test

    // Open a file to save the results
    FILE *file = fopen("combination_times.txt", "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return 1;
    }

    // Iterate through different values of n and k
    for (int ni = 0; ni < sizeof(n_values) / sizeof(n_values[0]); ni++) {
        for (int ki = 0; ki < sizeof(k_values) / sizeof(k_values[0]); ki++) {
            int n = n_values[ni];
            int k = k_values[ki];

            if (k > n || k <= 0 || n <= 0) {
                fprintf(file, "Invalid input: n = %d, k = %d\n", n, k);
                continue;
            }

            // Dynamically allocate memory for the combination array
            int *comb = (int *)malloc(k * sizeof(int));
            if (comb == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }

            // Initialize the first combination (1, 2, ..., k)
            for (int i = 0; i < k; i++) {
                comb[i] = i + 1;
            }

            // Measure the start time
            clock_t start_time = clock();

            // Generate and print all combinations
            int count = 0;
            do {
                count++;
                // printCombination(comb, k); // Uncomment if you want to print the combinations
            } while (nextCombination(comb, n, k));

            // Measure the end time and calculate the elapsed time
            clock_t end_time = clock();
            double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

            // Write the result to the file
            fprintf(file, "n = %d, k = %d, Combinations = %d, Time = %.6f seconds\n", n, k, count, elapsed_time);

            // Deallocate memory
            free(comb);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
