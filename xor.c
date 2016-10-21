#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "arg.h"
#include "util.h"

char *argv0;

int main(int argc, char **argv) {
    int rflag = 0;
    ARGBEGIN {
        case 'r': // repeat
            rflag = 1;
    } ARGEND

    if(argc < 2) {
        USAGE("[-r] file1 file2");
        exit(1);
    }

    FILE *f1 = argv[0][0] == '-' ? stdin : fopen(argv[0], "r");
    if(!f1) errx(2, "failed to open %s", argv[0]);
    FILE *f2 = argv[1][0] == '-' ? stdin : fopen(argv[1], "r");
    if(!f2) errx(2, "failed to open %s", argv[1]);
    if(f2 == stdin && rflag) errx(3, "cannot -r when reading from pipe");

    while(1) {
        char c1 = fgetc(f1);
        char c2 = fgetc(f2);
        if(c1 == EOF || (!rflag && c2 == EOF))
            break;
        if(c2 == EOF) {
            rewind(f2);
            c2 = fgetc(f2);
        }
        putchar(c1 ^ c2);
    }

    fclose(f1);
    fclose(f2);
}
