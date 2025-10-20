#include <stdio.h>

int main() {
    int sticks = 21, user;
    while(sticks > 0) {
        printf("Sticks left: %d\nPick 1-4: ", sticks);
        scanf("%d", &user);
        if(user < 1 || user > 4 || user > sticks) {
            printf("Invalid input!\n");
            continue;
        }
        sticks -= user;
        if(sticks == 0) {
            printf("You lost!\n");
            break;
        }
        int comp = 5 - user;
        printf("Computer picks: %d\n", comp);
        sticks -= comp;
    }
    return 0;
}
