#include <efi.h>
#include <init.h>
#include <graphic.h>

EFI_HANDLE ImageHandle;
EFI_SYSTEM_TABLE *SysTable;

EFI_STATUS EFI_MAIN(EFI_HANDLE IH, EFI_SYSTEM_TABLE *ST) {
    
    ImageHandle = IH;
    SysTable = ST;

    SysTable->ConOut->Reset(SysTable->ConOut, EFI_TRUE);
    SysTable->ConOut->OutputString(SysTable->ConOut, L"VizBoot Loading\r\n");

    print(L"Print func works\r\n");

    print(L"UEFI Vendor is ");
    print(SysTable->FirmwareVendor);
    print(L"\n\r");

    for(;;);
}