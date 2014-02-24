#include <stdio.h>

int simple_client(char *buf, int size);
void Hex_to_bin(unsigned char * source, unsigned char * dest);
unsigned short Hex_to_byte(unsigned char *buf, unsigned short default_value);
void Byte_to_hex(unsigned char *dest, unsigned char  fonte);
void Asc_to_hexasc(unsigned char * source, int sizeSource ,unsigned char * dest);