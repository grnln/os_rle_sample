cc = gcc

pack_in = rle_pack.c
unpack_in = rle_unpack.c
common_in = rle_common.c

pack_out = $(basename $(pack_in))
unpack_out = $(basename $(unpack_in))

cflags = -Wall -std=c99
ldflags = -lm

all: pack unpack

pack:
	$(cc) -O2 $(pack_in) $(common_in) $(cflags) $(ldflags) -o $(pack_out)

unpack:
	$(cc) -O2 $(unpack_in) $(common_in) $(cflags) $(ldflags) -o $(unpack_out)

clean:
	rm -rf $(pack_out) $(unpack_out)