# fpefi

bindings to UEFI and minimal entry point code for creating efi apps in
freepascal.

## what is covered?

* basic efi types
* system table
    * boot services
    * runtime services
    * required enums

## structure

* `bindings/` - main efi bindings
    * `efi.pas` - this is the unit you want to use
    * `efitypes.inc` - type declarations, including procedular types
    * `eficonts.inc` - diverse efi constants
    * `system.pas` - very minimal system unit
* `elf/` - entry point code for using elf binaries
    * `entry.asm` - entry point, adapted version from gnu-efi
    * `elf.pas` - contains elf relocation code and some elf types & constants
* `example` - example efi app using the elf entry point code
