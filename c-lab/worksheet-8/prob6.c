#include <stdio.h>
#include <string.h>

int isValid(char *s, char *p) {

    // If both string and pattern end → match
    if (*s == '\0' && *p == '\0')
        return 1;

    // If string ended but pattern remains
    if (*s == '\0') {
        while (*p == '*') p++;
        return *p == '\0';
    }

    // If pattern has '*'
    if (*p == '*') {
        return isValid(s, p + 1) || isValid(s + 1, p);
    }

    // If characters match or '?'
    if (*p == '?' || *p == *s) {
        return isValid(s + 1, p + 1);
    }

    return 0;
}

int main() {
    char s[100], p[20];

    printf("Enter the sentence : ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("Enter the pattern : ");
    scanf("%s", p);

    if (isValid(s, p)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
