#include <efi.h>
#include <init.h>
#include <graphic.h>

void print(CHAR16 *str) {
    SysTable->ConOut->OutputString(SysTable->ConOut, str);
}

CHAR16* itoa(uint64_t n, int basenumber) {
	static CHAR16 buffer[64];
	
	unsigned long int hold;
	int i, j;
	hold = n;
	i = 0;

	do{
		hold = n % basenumber;
		buffer[i++] = (hold < 10) ? (hold + '0') : (hold + 'a' - 10);
	} while(n /= basenumber);
	buffer[i--] = 0;
	
	for(j = 0; j < i; j++, i--)
	{
		hold = buffer[j];
		buffer[j] = buffer[i];
		buffer[i] = hold;
	}

	return buffer;
}

void printHex(uint64_t Val) {
	print(L"0x");
	print(itoa(Val, 16));
}
	
void printUint(uint64_t Val) {
	print(itoa(Val, 10));
}