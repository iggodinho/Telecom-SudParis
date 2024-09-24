#include <stdio.h>
#include <stdlib.h>

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
    int n, k;

    // Input n and k
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);

    if (k > n || k <= 0 || n <= 0) {
        printf("Invalid input: value must be 0 < k <= n.\n");
        return 1;
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

    // Print all combinations
    do {
        printCombination(comb, k);
    } while (nextCombination(comb, n, k));

    // Deallocate memory
    free(comb);

    return 0;
}