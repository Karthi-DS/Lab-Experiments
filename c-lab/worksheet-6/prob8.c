#include <stdio.h>

int main() {
    int n, i, j, max = 0, count = 0, total = 0, intmaxFreq = 0, freqNum;
    printf("Enter the number of artifacts\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the artifacts\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int freq[max + 1];
    for (i = 0; i <= max; i++) {
        freq[i] = 0;
    }

    // count frequency
    for (i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // sort (bubble sort)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }

    // find missing numbers
    int missing[max + 1];
    count = 0;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) continue; // skip duplicates
        for (int k = arr[i] + 1; k < arr[i + 1]; k++) {
            missing[count++] = k;
        }
    }

    // print sorted array
    printf("Sorted : [");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i + 1 < n) printf(",");
    }
    printf("]\n");

    // find most common + total of unique
    intmaxFreq = 0;
    freqNum = arr[0];
    for (i = 0; i <= max; i++) {
        if (freq[i] == 1) total += i;
        if (freq[i] > intmaxFreq || (freq[i] == intmaxFreq && i < freqNum)) {
            intmaxFreq = freq[i];
            freqNum = i;
        }
    }

    printf("The most common artifact is %d\n", freqNum);
    printf("The total of unique artifacts is %d\n", total);

    // print missing
    printf("Missing : [");
    for (i = 0; i < count; i++) {
        printf("%d", missing[i]);
        if (i + 1 < count) printf(",");
    }
    printf("]\n");

    return 0;
}



