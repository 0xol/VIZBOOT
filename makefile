cc = clang

all:

test:
	qemu-system-x86_64 -bios test/bios64.bin -hda test.img