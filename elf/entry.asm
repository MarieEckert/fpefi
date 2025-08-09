; nasm port and generally modified version of crt0-efi-x86_64.S
; ("EFI startup code") from gnuefi.

;********************************** LICENSE ***********************************;
; Copyright (C) 1999 Hewlett-Packard Co.
;   Contributed by David Mosberger <davidm@hpl.hp.com>.
; Copyright (C) 2005 Intel Co.
;   Contributed by Fenghua Yu <fenghua.yu@intel.com>.
; Copyright (C) 2025 Marie Eckert
;   Translation to NASM and further modifications.
;
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
;
; * Redistributions of source code must retain the above copyright
;   notice, this list of conditions and the following disclaimer.
; * Redistributions in binary form must reproduce the above
;   copyright notice, this list of conditions and the following
;   disclaimer in the documentation and/or other materials
;   provided with the distribution.
; * Neither the name of Hewlett-Packard Co. nor the names of its
;   contributors may be used to endorse or promote products derived
;   from this software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
; CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
; INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
; MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
; BE LIABLE FOR ANYDIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
; OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
; PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
; TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
; THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
; SUCH DAMAGE.
;******************************************************************************;

BITS 64

global _start

extern ImageBase
extern _DYNAMIC
extern _relocate
extern efi_main

section .text align=4
_start:		sub		rsp, 8
			push	rdx		; ImageHandle
			push	rcx		; SystemTable (both of these are also passed along
							;              _relocate)

			; _relocate(ImageBase,Dynamic, ImageHandle, SystemTable)
			lea		rdi, [rel ImageBase]
			lea		rsi, [rel _DYNAMIC]
			call	_relocate

			; _entry(ImageHandle, SystemTable)
			pop		rdi
			pop		rsi
			call	efi_main

			add		rsp, 8
.exit:		ret

; dummy reloc section "so EFI knows it's a relocatable executable"
section .data
dummy:		dd		0

section .reloc align=4
_reloc:		dd		dummy - _reloc
			dd		12
			dd		0

section .note.GNU-stack progbits alloc noexec nowrite
