#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseWords(char *s) {
	char words[1000];
	char result[1000];
	int len = strlen(s);
	int i = len-1,k;

	while (i>0) {
		while (i>=0 && isspace(s[i]))i--;

		k = 0;
		if (i<0) return;
		while(i>=0 && !isspace(s[i])) {
			words[k++] = s[i--];
		}
		words[k] = '\0';
        for(int l=0,r=k-1;l<r;l++,r--){
            char tmp = words[l];
            words[l] = words[r];
            words[r] = tmp;
        }
        if (strlen(result) > 0) {
            strcat(result, " ");
        }

        strcat(result, words);
        
	}
	printf("%s",result);
}

int main() {
	char s[1000];
	printf("Enter text: ");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")] = '\0';
	reverseWords(s);
}