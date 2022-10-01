#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <efi.h>

void print(CHAR16 *str);
CHAR16* itoa(uint64_t val, int base);
void printHex(uint64_t Val);
void printUint(uint64_t Val);

#endif