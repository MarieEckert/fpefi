{$mode fpc}
unit app;

interface

uses efi, elf;

implementation

function efi_main(ImageHandle: TEfiHandle; SystemTable: PEfiSystemTable):
	TEfiStatus; cdecl; [public, alias: 'efi_main'];
begin
	SystemTable^.ConOut^.OutputString(SystemTable^.ConOut, 'Hello, World!'#13#10);
	exit(EFI_SUCCESS);
end;

end.
