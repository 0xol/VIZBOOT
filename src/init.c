#include "efi.h"

EFI_STATUS EFI_MAIN(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SysTable) {
    
    SysTable->ConOut->Reset(SysTable->ConOut, EFI_TRUE);
    
    for(;;);
}