#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefixSum = 0;
    long long count = 0;

    // Using large hash range (for constraints safety)
    // We'll shift index by 1000000 to handle negative sums
    int size = 2000001;
    long long *freq = calloc(size, sizeof(long long));

    // prefix sum 0 appears once initially
    freq[1000000] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = prefixSum + 1000000;

        count += freq[index];
        freq[index]++;
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}