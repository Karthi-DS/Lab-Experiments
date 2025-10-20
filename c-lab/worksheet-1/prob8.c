#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Factors: ");
    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            printf("%d ", i);
            sum += i;
        }
    }
    if(sum == n) 
        printf("\n%d is perfect\n", n);
    else 
        printf("\n%d is not perfect\n", n);
    return 0;
}
