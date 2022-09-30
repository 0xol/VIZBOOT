cc = clang
ld = lld-link

ccflags = -target x86_64-pc-win32-coff -fno-stack-protector -I efi -I src/include -fshort-wchar -mno-red-zone -c
lflags = -subsystem:efi_application -nodefaultlib -dll

all:
	clear
	clear
	
	$(cc) $(ccflags) src/init.c -o bin/init.o
	$(cc) $(ccflags) src/graphic.c -o bin/graphic.o

	$(ld) $(lflags) -entry:EFI_MAIN bin/*.o -out:BOOTX64.EFI
	rm BOOTX64.lib


testimg:all
	dd if=/dev/zero of=VIZ.img bs=512 count=20480
	mformat -i VIZ.img -f 1440 ::
	mmd -i VIZ.img /EFI
	mmd -i VIZ.img /EFI/BOOT
	mcopy -i VIZ.img BOOTX64.EFI ::/EFI/BOOT/


qemu:
	qemu-system-x86_64 -bios bios64.bin -drive format=raw,unit=0,file=VIZ.img