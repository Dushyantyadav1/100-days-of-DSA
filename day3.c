#include <stdio.h>

int linearSearch(int arr[], int n, int k, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++; // Increment comparison count
        if (arr[i] == k) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n, k;
    int arr[100]; // Assuming max array size is 100

    // Read array size
    if (scanf("%d", &n) != 1) return 1;

    // Read array elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    // Read key to search
    if (scanf("%d", &k) != 1) return 1;

    int comparisons_count;
    int index = linearSearch(arr, n, k, &comparisons_count);

    if (index != -1) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons_count);

    return 0;
}
