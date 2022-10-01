#include <efi.h>
#include <init.h>
#include <graphic.h>

EFI_HANDLE ImageHandle;
EFI_SYSTEM_TABLE *SysTable;

#define NULL ((void *)0)

EFI_STATUS EFI_MAIN(EFI_HANDLE IH, EFI_SYSTEM_TABLE *ST) {
    
    ImageHandle = IH;
    SysTable = ST;

    SysTable->ConOut->Reset(SysTable->ConOut, EFI_TRUE);
    SysTable->ConOut->OutputString(SysTable->ConOut, L"VizBoot Loading\r\n");

    print(L"Print func works\r\n");

    CHAR16 DisableWatchDog;
    SysTable->BootServices->SetWatchdogTimer(0, 0xFFFF0, 2, &DisableWatchDog);
    print(L"Watchdog Timer Disabled\r\n");

    print(L"UEFI Vendor is ");
    print(SysTable->FirmwareVendor);
    print(L"\n\r");


    EFI_MEMORY_DESCRIPTOR*   memMap = NULL;
    UINTN                    memMapSize = 0;
    UINTN                    memMapDescSize = 0;
    UINTN                    memMapKey = 0;
    uint64_t                 memMapNumEntries = 0;
    UINT32                   memMapDescVer = 0;
    

    SysTable->BootServices->GetMemoryMap(&memMapSize, NULL, &memMapKey, &memMapDescSize, &memMapDescVer);
    memMapSize = (memMapSize + 4095 );
    SysTable->BootServices->AllocatePages(AllocateAnyPages, EfiLoaderData, memMapSize, (EFI_PHYSICAL_ADDRESS*)&memMap);
    SysTable->BootServices->GetMemoryMap(&memMapSize, memMap, &memMapKey, &memMapDescSize, &memMapDescVer);
    
    uint64_t TotalPage = 0;

    memMapNumEntries = memMapSize / memMapDescSize;

    void *mm = memMap;

    for (uint64_t i = 0; i < memMapNumEntries; i++)
    {   
        memMap = (EFI_MEMORY_DESCRIPTOR *)mm;
        
        TotalPage += memMap->NumberOfPages;
        
        mm += memMapDescSize;
    }

    print(L"Total system memory: ");
    printUint(TotalPage * 4096 / 1024 / 1024);
    print(L" MB\r\n");

    for(;;);
}