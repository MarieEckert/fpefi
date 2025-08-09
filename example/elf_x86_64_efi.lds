OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
	. = 0;
	ImageBase = .;

	/* hash must come first */
	.hash : { *(.hash) }

	. = ALIGN(4096);

	.text :
	{
		_text = .;
		*(.text)
		*(.text.*)
		*(.plt)
		. = ALIGN(16);
	}
	_etext = .;

	. = ALIGN(4096);
	.reloc :
	{
		KEEP(*(.reloc))
	}

	. = ALIGN(4096);
	.data :
	{
		_data = .;
		*(.got.plt)
		*(.got)
		*(.data*)
		*(.sdata)

		/* Fold BSS into .data for EFI loaders */
		*(.sbss)
		*(.scommon)
		*(.dynbss)
		*(.bss*)
		*(COMMON)
	}
	_edata = .;

	. = ALIGN(4096);
	.dynamic : { *(.dynamic) }

	. = ALIGN(4096);
	.rela :
	{
		*(.rela.text*)
		*(.rela.data*)
		*(.rela.got)
		*(.rela.dyn)
	}

	. = ALIGN(4096);
	.rela.plt : { *(.rela.plt) }

	. = ALIGN(4096);
	.rodata : { *(.rodata*) }

	. = ALIGN(4096);
	.dynsym : { *(.dynsym) }

	. = ALIGN(4096);
	.dynstr : { *(.dynstr) }
}
