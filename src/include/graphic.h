#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <efi.h>

void print(CHAR16 *str);
CHAR16* itoa(int64_t val, int base);

#endif