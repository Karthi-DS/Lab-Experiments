#include <stdio.h>

int main() {
    int num, den;

    printf("Fractions where Sleepy's Technique works:\n");

    for (num = 10; num < 100; num++) {       
        for (den = num + 1; den < 100; den++) { 

            int n1 = num / 10, n2 = num % 10; 
            int d1 = den / 10, d2 = den % 10; 

            if (n2 == d1 && n2 != 0) {
                if ((num * d2) == (den * n1)) {
                    printf("%d/%d = %d/%d\n", num, den, n1, d2);
                }
            }

            if (n1 == d2 && n1 != 0) {
                if ((num * d1) == (den * n2)) {
                    printf("%d/%d = %d/%d\n", num, den, n2, d1);
                }
            }
        }
    }

    return 0;
}