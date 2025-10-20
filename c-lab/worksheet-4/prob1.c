#include <stdio.h>

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers (1..N with one duplicate and one missing):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long sum = 0, sqSum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sqSum += (long long)arr[i] * arr[i];
    }

    long long expectedSum = (long long)n * (n + 1) / 2;
    long long expectedSqSum = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long diff1 = sum - expectedSum;          // Duplicate - Missing
    long long diff2 = sqSum - expectedSqSum;      // Duplicate² - Missing²

    long long sumDM = diff2 / diff1;              // Duplicate + Missing

    long long duplicate = (diff1 + sumDM) / 2;
    long long missing = duplicate - diff1;

    printf("Duplicate: %lld\n", duplicate);
    printf("Missing : %lld\n", missing);

    return 0;
} 
