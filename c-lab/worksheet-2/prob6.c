
#include <stdio.h>
#include <math.h>

int main() {
    double x, term, sum = 0.0;
    int n;

    printf("Enter value of x: ");
    scanf("%lf", &x);

    for (n = 0; n < 20; n++) {
        // compute each term: [(-1)^n / (n!)^2] * (x/2)^(2n)
        double numerator = pow(-1, n) * pow(x / 2.0, 2 * n);
        double denominator = pow(tgamma(n + 1), 2); // (n!)^2, tgamma(n+1) = n!
        term = numerator / denominator;
        sum += term;
    }

    printf("J0(%lf) ≈ %lf (using first 20 terms)\n", x, sum);

    return 0;
}
