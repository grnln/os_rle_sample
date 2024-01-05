#include "rle_common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

uint8_t *rle_pack(uint8_t *buffer, uint16_t width, uint16_t height, uint32_t *len) {
    uint32_t out_len = 0;
    uint8_t *out = malloc(2 * width * height);

    for (uint16_t j = 0; j < height; j++) {
        uint16_t pos = 0;
        uint8_t scanline[2 * width];
        memset(scanline, 0, 2 * width);

        for (uint16_t i = 0; i < width; i++) {
            uint8_t current = buffer[(j * width) + i];
            uint8_t next = buffer[(j * width) + i + 1];

            scanline[pos + 1] = current;
            scanline[pos]++;
            
            if (scanline[pos + 1] != next) {
                pos += 2;
            }
        }
        memcpy(out + out_len, scanline, pos + 2);
        out_len += (pos + 2);
    }
    (*len) = out_len;
    return out;
}

int main(int argc, char **argv) {
    uint8_t *in_buffer, *out_buffer;
    uint32_t in_len, out_len;

    in_buffer = read_file("example.bin", &in_len);
    out_buffer = rle_pack(in_buffer, 64, 64, &out_len);

    write_file("example_compressed.bin", out_buffer, out_len);

    free(in_buffer);
    free(out_buffer);
    
    return 0;
}