#include <stdio.h>

int isPalindrome(int n) {
    int rev = 0, temp = n;
    while(temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == n;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    n++;
    while(!isPalindrome(n)) 
        n++;
    printf("Next palindrome: %d\n", n);
    return 0;
}
