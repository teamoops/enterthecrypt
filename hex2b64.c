#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main() {
    size_t size;
    char *byte_arr = fread_hex(stdin, &size);
    FILE *f = popen("base64", "w");
    for(int i = 0; i < size; i++)
        fprintf(f, "%c", byte_arr[i]);
    free(byte_arr);
    pclose(f);
    return 0;
}
