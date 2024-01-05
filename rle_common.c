#include "rle_common.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

uint8_t *read_file(const char *path, uint32_t *len) {
    uint8_t *buffer;
    struct stat st;

    FILE *ptr = fopen(path, "rb");

    stat(path, &st);
    
    (*len) = st.st_size;
    buffer = malloc(st.st_size);

    fread(buffer, sizeof(uint8_t), st.st_size, ptr);
    fclose(ptr);

    return buffer;
}

void write_file(const char *path, uint8_t *buffer, uint32_t len) {
    FILE *ptr = fopen(path, "wb");

    fwrite(buffer, sizeof(uint8_t), len, ptr);    
    fclose(ptr);
}