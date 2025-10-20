#include <stdio.h>

int main() {
    printf(" y    x      i\n");
    for(int y = 1; y <= 6; y++) {
        for(int x = 55; x <= 125; x += 5) {
            double x_val = x / 10.0;
            double i = 2 + y + 0.5 * x_val;
            printf("%2d  %4.1f  %6.2f\n", y, x_val, i);
        }
    }
    return 0;
}

