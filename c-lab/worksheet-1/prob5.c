#include <stdio.h>

int main() {
    int a, b, big;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    big = (a > b) ? a : b;   // ternary operator to find biggest

    printf("The biggest number is: %d\n", big);

    return 0;
}
