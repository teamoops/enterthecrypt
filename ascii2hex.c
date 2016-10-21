#include <stdio.h>

int main() {
    char b;
    while(scanf("%2hhx", &b) >= 0)
        putchar(b);
    return 0;
}
