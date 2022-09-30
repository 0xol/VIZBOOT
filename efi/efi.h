#ifndef EFI_H
#define EFI_H

#include <stdint.h>


#define EFI_FALSE       0
#define EFI_TRUE        1

#define EFI_SUCCESS     0x0000000000000000
#define EFI_ERR         0x8000000000000000

typedef uint64_t        EFI_STATUS;

#endif