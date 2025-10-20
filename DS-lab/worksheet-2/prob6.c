#include <stdio.h>

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key (rotation count): ");
    scanf("%d", &key);

    key = key % n;  // handle if key > n

    printf("Rotated Array: ");
    for (int i = key; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < key; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}