{$mode fpc}
unit elf;

interface

type
	TElf64XWord		= UInt64;
	TElf64SXWord	= Int64;
	TElf64Addr		= UInt64;
	TElf64Half		= UInt16;
	TElf64Word		= UInt32;
	TElf64Off		= UInt64;

{$packrecords c}
	TElf64Hdr = record
		e_ident:		array [0..15] of Char;
		e_type:			TElf64Half;
		e_machine:		TElf64Half;
		e_version:		TElf64Word;
		e_entry:		TElf64Addr;
		e_phoff:		TElf64Off;
		e_shoff:		TElf64Off;
		e_flags:		TElf64Word;
		e_ehsize:		TElf64Half;
		e_phentsize:	TElf64Half;
		e_phnum:		TElf64Half;
		e_shentsize:	TElf64Half;
		e_shnum: 		TElf64Half;
		e_shstrndx:		TElf64Half;
	end;

	TElf64Phdr = record
		p_type		: TElf64Word;
		p_flags		: TElf64Word;
		p_offset	: TElf64Off;
		p_vaddr		: TElf64Addr;
		p_paddr		: TElf64Addr;
		p_filesz	: TElf64XWord;
		p_memsz		: TElf64XWord;
		p_align		: TElf64XWord;
	end;

	TElf64Dyn = record
		d_tag	: TElf64SXWord;
		case Byte of
			0: (d_val	: TElf64XWord);
			1: (d_ptr	: TElf64Addr);
	end;

	TElf64Rel = record
		r_offset	: TElf64Addr;
		r_info		: TElf64XWord;
	end;
{$packrecords default}

	PElf64Hdr	= ^TElf64Hdr;
	PElf64Phdr	= ^TElf64Phdr;
	PElf64Dyn	= ^TElf64Dyn;
	PElf64Rel	= ^TElf64Rel;

const
	ELF_RELOC_SUCCESS	= 0;
	ELF_RELOC_ERROR		= UInt64((1 shl 63) or 1);

	PT_NULL		= 0;
	PT_LOAD		= 1;
	PT_DYNAMIC	= 2;
	PT_INTERP	= 3;
	PT_NOTE		= 4;
	PT_SHLIB	= 5;
	PT_PHDR		= 6;
	PT_TLS		= 7;
	PT_LOOS		= $60000000;
	PT_HIOS		= $6fffffff;
	PT_LOPROC	= $70000000;
	PT_HIPROC	= $7fffffff;

	DT_NULL				= 0;
	DT_NEEDED			= 1;
	DT_PLTRELSZ			= 2;
	DT_PLTGOT			= 3;
	DT_HASH				= 4;
	DT_STRTAB			= 5;
	DT_SYMTAB			= 6;
	DT_RELA				= 7;
	DT_RELASZ			= 8;
	DT_RELAENT			= 9;
	DT_STRSZ			= 10;
	DT_SYMENT			= 11;
	DT_INIT				= 12;
	DT_FINI				= 13;
	DT_SONAME			= 14;
	DT_RPATH			= 15;
	DT_SYMBOLIC			= 16;
	DT_REL				= 17;
	DT_RELSZ			= 18;
	DT_RELENT			= 19;
	DT_PTRREL			= 20;
	DT_DEBUG			= 21;
	DT_TEXTREL			= 22;
	DT_JMPREL			= 23;
	DT_BIND_NOW			= 24;
	DT_INIT_ARRAY		= 25;
	DT_FINI_ARRAY		= 26;
	DT_INIT_ARRAYSZ		= 27;
	DT_FINI_ARRAYSZ		= 28;
	DT_RUNPATH			= 29;
	DT_FLAGS			= 30;
	DT_ENCODING			= 32;
	DT_PREINIT_ARRAY	= 32;
	DT_PREINIT_ARRAYSZ	= 33;
	DT_NUM				= 34;
	DT_LOOS				= $6000000d;
	DT_HIOS				= $6ffff000;
	DT_LOPROC			= $70000000;
	DT_HIPROC			= $7fffffff;

	R_X86_64_NONE		= 0;
	R_X86_64_64			= 1;
	R_X86_64_PC32		= 2;
	R_X86_64_GOT32		= 3;
	R_X86_64_PLT32		= 4;
	R_X86_64_COPY		= 5;
	R_X86_64_GLOB_DAT	= 6;
	R_X86_64_JUMP_SLOT	= 7;
	R_X86_64_RELATIVE	= 8;
	R_X86_64_GOTPCREL	= 9;
	R_X86_64_32			= 10;
	R_X86_64_32S		= 11;
	R_X86_64_16			= 12;
	R_X86_64_PC16		= 13;
	R_X86_64_8			= 14;
	R_X86_64_PC8		= 15;
	R_X86_64_DTPMOD64	= 16;
	R_X86_64_DTPOFF64	= 17;
	R_X86_64_TPOFF64	= 18;
	R_X86_64_TLSGD		= 19;
	R_X86_64_TLSLD		= 20;
	R_X86_64_DTPOFF32	= 21;
	R_X86_64_GOTTPOFF	= 22;
	R_X86_64_TPOFF32	= 23;
	R_X86_64_NUM		= 24;

implementation

{ position independent x86_64 elf so relocator.
  This is a more or less direct port of the gnuefi elf relocator
  (reloc_x86_64.c) and designed to be compatible with the 
  gnuefi crt0-efi-x86_64.S entry point.
}
function _relocate(
			ldbase: Int64;
			dyn: PElf64Dyn
		): UInt64; SYSV_ABI_Cdecl; [public, alias: '_relocate'];
var
	rel				: PElf64Rel;
	addr			: PUInt64;
	relsz, relent	: Int64;
begin
	relsz := 0;
	relent := 0;
	rel := Nil;

	while dyn^.d_tag <> DT_NULL do
	begin
		case dyn^.d_tag of
		DT_RELA: rel := PElf64Rel(UInt64(dyn^.d_ptr) + ldbase);
		DT_RELASZ: relsz := dyn^.d_val;
		DT_RELAENT: relent := dyn^.d_val;
		end;
		inc(dyn);
	end;

	if (rel = Nil) and (relent = 0) then
		exit(ELF_RELOC_SUCCESS);

	if (rel = Nil) or (relent = 0) then
		exit(ELF_RELOC_ERROR);

	{ Apply the relocations }
	while relsz > 0 do
	begin
		case rel^.r_info and $ffffffff of
		R_X86_64_RELATIVE: begin
			addr := PUInt64(ldbase + rel^.r_offset);
			addr^ := addr^ + ldbase;
		end;
		end;

		rel := PElf64Rel(PChar(rel) + relent);
		relsz := relsz - relent;
	end;

	exit(ELF_RELOC_SUCCESS);
end;

end.
