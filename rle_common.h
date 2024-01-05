#ifndef _RLE_COMMON_H_
#define _RLE_COMMON_H_

#include <stdint.h>

uint8_t *read_file(const char *path, uint32_t *len);
void write_file(const char *path, uint8_t *buffer, uint32_t len);

#endif