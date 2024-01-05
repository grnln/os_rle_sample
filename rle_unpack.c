#include "rle_common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

uint8_t *rle_unpack(uint8_t *buffer, uint16_t width, uint16_t height, uint32_t len) {
    uint32_t out_len = 0;
    uint8_t *out = malloc(width * height);

    for (uint32_t i = 0; i < len; i += 2) {
        for (uint8_t j = 0; j < buffer[i]; j++) {
            out[out_len] = buffer[i + 1];
            out_len++;
        }
    }
    return out;
}

int main(int argc, char **argv) {
    uint8_t *in_buffer, *out_buffer;
    uint32_t in_len, out_len = 64 * 64;

    in_buffer = read_file("example_compressed.bin", &in_len);
    out_buffer = rle_unpack(in_buffer, 64, 64, in_len);

    write_file("example_uncompressed.bin", out_buffer, out_len);

    free(in_buffer);
    free(out_buffer);

    return 0;
}