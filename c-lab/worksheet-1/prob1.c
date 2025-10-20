#include <stdio.h>
#include <math.h>

int main() {
    float x, f;

    printf("Enter value of x: ");
    scanf("%f", &x);

    f = (pow(x, 3) - 2*pow(x, 2) + x - 6.3) / (pow(x, 2) + 0.05*x + 3.14);

    printf("The value of f is: %.4f\n", f);

    return 0;
}
