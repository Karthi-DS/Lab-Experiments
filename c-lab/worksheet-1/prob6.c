#include <stdio.h>

int main() {
    int i, j, rows, choice;

    printf("Choose a pattern:\n");
    printf("1. Right Triangle\n");
    printf("2. Pyramid\n");
    printf("3. Diamond\n");
    printf("4. Right Arrow\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    switch(choice) {
        case 1: 
            printf("\nRight Triangle:\n");
            for(i = 1; i <= rows; i++) {
                for(j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;

        case 2: 
            printf("\nPyramid:\n");
            for(i = 1; i <= rows; i++) {
                for(j = 1; j <= rows - i; j++) {
                    printf(" ");
                }
                for(j = 1; j <= 2 * i - 1; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 3: 
            printf("\nDiamond:\n");
            for(i = 1; i <= rows; i++) {
                for(j = 1; j <= rows - i; j++) {
                    printf(" ");
                }
                for(j = 1; j <= 2 * i - 1; j++) {
                    printf("*");
                }
                printf("\n");
            }
            for(i = rows - 1; i >= 1; i--) {
                for(j = 1; j <= rows - i; j++) {
                    printf(" ");
                }
                for(j = 1; j <= 2 * i - 1; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 4: 

    printf("\nRight Arrow:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        for(j = 0; j < rows - i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for(i = rows - 2; i >= 0; i--) {
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        for(j = 0; j < rows - i; j++) {
            printf("*");
        }
        printf("\n");
    }
    break;



        default:
            printf("Invalid choice\n");
    }

    return 0;
}

