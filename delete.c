#include <stdio.h>

int main() {
    int n, pos, i;

    // Input the number of elements
    if (scanf("%d", &n) != 1) return 1;
    int arr[n];

    // Input the elements of the array
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    // Input the 1-based position to delete
    if (scanf("%d", &pos) != 1) return 1;

    // Adjust pos to 0-based index
    int index_to_delete = pos - 1;

    // Check if the position is valid
    if (index_to_delete < 0 || index_to_delete >= n) {
        // Optional: Handle error or just proceed if constraints guarantee validity
        // printf("Invalid position\n");
    } else {
        // Shift remaining elements to the left
        for (i = index_to_delete; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // The array now effectively has (n - 1) elements
        n--;
    }

    // Print the updated array
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

