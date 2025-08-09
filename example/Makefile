PC = fpc
PFLAGS = -Aelf -O3 -Op3 -Si -Sc -Sg -Xd -CX -XXs -Px86_64 -Rintel -Tlinux \
		 -Fu"../bindings" -Fu"../elf" -FE"obj"

AS = nasm
ASFLAGS = -felf64

LD = ld
LDFLAGS = -shared -Bsymbolic  -Telf_x86_64_efi.lds

OBJCOPY_FLAGS = -j .text -j .sdata -j .data -j .rodata -j .dynamic -j .dynsym \
				-j .rel -j .rela -j .rel.* -j .rela.* -j .reloc \
				--target efi-app-x86_64 --subsystem=10

app.efi: app.so
	objcopy $(OBJCOPY_FLAGS) $^ $@

app.so: app.o entry.o
	$(LD) $(LDFLAGS) obj/*.o -o $@

.PHONY: app.o
app.o: dirs
	$(PC) app.pas $(PFLAGS)

entry.o: ../elf/entry.asm | dirs
	$(AS) $^ -o obj/$@ $(ASFLAGS)

.PHONY: dirs
dirs:
	mkdir -p obj

.PHONY: clean
clean:
	rm obj/*.o
	rm obj/*.ppu
	rm *.so
	rm *.efi
