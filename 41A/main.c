#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

char* reverse_string(char* in, int n) {
    char* out = (char*) malloc((n+1) * sizeof(char));
    for(int i=0; i < n; i++)
        out[n-1-i] = in[i];
    out[n] = '\0';

    return out;
}

int main() {
    char s[101], t[101];
    scanf("%100s", &s[0]);
    scanf("%100s", &t[0]);

    char* reversed = reverse_string(s, strlen(s));
    int r = strcmp(t, reversed);
    (r == 0) ? printf("YES") : printf("NO");


    return 0;
}