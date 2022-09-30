#include "efi.h"

EFI_STATUS EFI_MAIN(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SysTable) {
    
    SysTable->ConOut->Reset(SysTable->ConOut, EFI_TRUE);
    SysTable->ConOut->EnableCursor(SysTable->ConOut, EFI_TRUE);
    SysTable->ConOut->OutputString(SysTable->ConOut, L"VIZBOOT\r\n");
    
    for(;;);
}