#include <efi.h>
#include <init.h>
#include <graphic.h>

void print(CHAR16 *str) {
    SysTable->ConOut->OutputString(SysTable->ConOut, str);
}

CHAR16* itoa(int64_t val, int base){
	
	static CHAR16 buf[64] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}
	