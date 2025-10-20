#include <stdio.h>

void generate_magic_square(int n, int a[n][n]) {
    // Initialize to 0
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            a[r][c] = 0;

    int num = 1;
    int r = 0, c = n / 2;            

    while (num <= n * n) {
        a[r][c] = num++;

        int nr = (r - 1 + n) % n;    
        int nc = (c + 1) % n;        

        if (a[nr][nc] != 0) {     
            r = (r + 1) % n;
            // c stays the same
        } else {
            r = nr;
            c = nc;
        }
    }
}

int check_magic_square(int n, int a[n][n]) {
    int magic_sum = n * (n * n + 1) / 2;

    // Check rows and columns
    for (int i = 0; i < n; i++) {
        int rs = 0, cs = 0;
        for (int j = 0; j < n; j++) {
            rs += a[i][j];
            cs += a[j][i];
        }
        if (rs != magic_sum || cs != magic_sum) return 0;
    }

    // Diagonals
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        d1 += a[i][i];
        d2 += a[i][n - 1 - i];
    }
    return (d1 == magic_sum && d2 == magic_sum);
}

int main(void) {
    int n;
    printf("Enter an odd order n (>=3): ");
    if (scanf("%d", &n) != 1 || n < 3 || n % 2 == 0) {
        printf("Please enter a valid odd integer >= 3.\n");
        return 1;
    }

    int a[n][n];
    generate_magic_square(n, a);

    printf("\nMagic square of order %d (magic sum %d):\n", n, n * (n * n + 1) / 2);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            printf("%4d", a[r][c]);
        printf("\n");
    }

    if (check_magic_square(n, a))
        printf("\nVerification: OK – it is a magic square.\n");
    else
        printf("\nVerification: FAILED.\n");

    return 0;
}

