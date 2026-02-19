#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = 1000000000;
    int result1 = arr[left], result2 = arr[right];

    // Step 2: Two pointer technique
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            result1 = arr[left];
            result2 = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", result1, result2);

    return 0;
}
