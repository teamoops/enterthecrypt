#ifndef UTIL_H
#define UTIL_H
#include <stdlib.h>

#define MAX_BYTES 512

char *fread_hex(FILE *f, size_t *size) {
    char *byte_arr = calloc(sizeof(char), MAX_BYTES);
    int i = 0;
    while(fscanf(f, "%2hhx", &byte_arr[i]) >= 0) i++;
    *size = i;
    return byte_arr;
}

#endif // UTIL_H
