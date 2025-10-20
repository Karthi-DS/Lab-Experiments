#include <stdio.h>

int main() {
    float scores[8], sum = 0, min, max;
    
    printf("Enter 8 scores out of ten points:\n");
    for (int i = 0; i < 8; i++) {
        scanf("%f", &scores[i]);
        sum += scores[i];
    }

    min = max = scores[0];
    for (int i = 1; i < 8; i++) {
        if (scores[i] < min) min = scores[i];
        if (scores[i] > max) max = scores[i];
    }

    float total = sum - (min + max);
    float avg = total / 6; // remaining 6 scores

    printf("Your lowest score is %.2f\n", min);
    printf("Your maximum score is %.2f\n", max);
    printf("Your total point is %.2f\n", total);
    printf("Your average point is %.2f\n", avg);

    return 0;
}
