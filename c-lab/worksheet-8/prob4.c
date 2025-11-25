#include <stdio.h>
#include <string.h>

void longestHappyString(int a, int b, int c, char result[]) {
    int i = 0;
    
    while (a > 0 || b > 0 || c > 0) {
        char ch = ' ';
        if (a >= b && a >= c) ch = 'a';
        else if (b >= a && b >= c) ch = 'b';
        else ch = 'c';

        int len = strlen(result);
        if (len >= 2 && result[len-1] == ch && result[len-2] == ch) {
            if (ch == 'a') {
                if (b >= c && b > 0) ch = 'b';
                else if (c > 0) ch = 'c';
                else break;
            } 
            else if (ch == 'b') {
                if (a >= c && a > 0) ch = 'a';
                else if (c > 0) ch = 'c';
                else break;
            }
            else {
                if (a >= b && a > 0) ch = 'a';
                else if (b > 0) ch = 'b';
                else break;
            }
        }

        // Add character to result
        result[i++] = ch;
        result[i] = '\0';

        // Decrease respective counter
        if (ch == 'a') a--;
        else if (ch == 'b') b--;
        else c--;
    }
}

int main() {
    int a, b, c;
    char result[1000] = "";

    printf("Enter a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    longestHappyString(a, b, c, result);

    printf("Longest Happy String: %s\n", result);
    return 0;
}
