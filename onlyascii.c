#include <stdio.h>

int main() {
    char c;
    while((c = getc(stdin)) != EOF)
        if(c >= 32 && c <= 126)
            putchar(c);
}
