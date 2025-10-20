#include <stdio.h>

int main() {
    int d, m, c, y, ns, as, f;
    printf("Enter date (DD MM CCYY): ");
    scanf("%d %d %d", &d, &m, &y);
    
    c = y / 100;
    y %= 100;
    if(m < 3) {
        m += 12;
        y--;
    }
    ns = c / 4 - 2 * c - 1;
    as = 5 * y / 4;
    f = d + (26 * (m + 1)) / 10 + ns + as;
    f %= 7;
    if(f < 0) f += 7;
    
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Day: %s\n", days[f]);
    return 0;
}
