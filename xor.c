#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "util.h"

int main(int argc, char **argv) {
    if(argc < 3) {
        USAGE("file1 file2");
        exit(1);
    }
    FILE *f1 = argv[1][0] == '-' ? stdin : fopen(argv[1], "r");
    FILE *f2 = argv[2][0] == '-' ? stdin : fopen(argv[2], "r");

    while(1) {
        char c1 = fgetc(f1);
        char c2 = fgetc(f2);
        if(c1 == EOF || c2 == EOF)
            break;
        putchar(c1 ^ c2);
    }

    fclose(f1);
    fclose(f2);
}
