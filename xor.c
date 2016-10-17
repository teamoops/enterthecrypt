#include <stdio.h>
#include <err.h>
#include "util.h"

int usage() {
    fprintf(stderr, "xor: file1 file2");
}

int main(int argc, char **argv) {
    if(argc < 3) {
        usage();
        exit(1);
    }
    size_t s1;
    FILE *f1 = fopen(argv[1], "r");
    char *h1 = fread_hex(f1, &s1);

    size_t s2;
    FILE *f2 = fopen(argv[2], "r");
    char *h2 = fread_hex(f2, &s2);

    if (s1 != s2)
        err(2, "hex strings are not the same length");

    for(int i = 0; i < s1; i++) {
        h1[i] ^= h2[i];
        printf("%c", h1[i]);
    }
}
