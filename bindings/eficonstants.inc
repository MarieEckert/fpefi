// vim: set filetype=pascal :

{ constant definitions for interfacing with EFI.
  you probably shouldn't include this file directly, you should use the efilib
  unit.

  Built with the UEFI Specifcation Version 2.6.
}

{ Copyright (c) 2025, Marie Eckert

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

  3. Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
}

{$ifndef EFILIB_EFICONSTANTS_INC}
{$define EFILIB_EFICONSTANTS_INC}

{$include efitypes.inc}

const
	{ EFI_STATUS Codes }
	{ EFI_STATUS Success Codes (High Bit Clear) [Table 235] }
	EFI_SUCCESS					: TEfiStatus = 0;

	{ EFI_STATUS Error Codes (High Bit Set) [Table 236] }
	EFI_LOAD_ERROR				: TEfiStatus = UInt64((1 shl 63) or 1);
	EFI_INVALID_PARAMETER		: TEfiStatus = UInt64((1 shl 63) or 2);
	EFI_UNSUPPORTED				: TEfiStatus = UInt64((1 shl 63) or 3);
	EFI_BAD_BUFFER_SIZE			: TEfiStatus = UInt64((1 shl 63) or 4);
	EFI_BUFFER_TOO_SMALL		: TEfiStatus = UInt64((1 shl 63) or 5);
	EFI_NOT_READY				: TEfiStatus = UInt64((1 shl 63) or 6);
	EFI_DEVICE_ERROR			: TEfiStatus = UInt64((1 shl 63) or 7);
	EFI_WRITE_PROTECTED			: TEfiStatus = UInt64((1 shl 63) or 8);
	EFI_OUT_OF_RESOURCES		: TEfiStatus = UInt64((1 shl 63) or 9);
	EFI_VOLUME_CORRUPTED		: TEfiStatus = UInt64((1 shl 63) or 10);
	EFI_VOLUME_FULL				: TEfiStatus = UInt64((1 shl 63) or 11);
	EFI_NO_MEDIA				: TEfiStatus = UInt64((1 shl 63) or 12);
	EFI_MEDIA_CHANGED			: TEfiStatus = UInt64((1 shl 63) or 13);
	EFI_NOT_FOUND				: TEfiStatus = UInt64((1 shl 63) or 14);
	EFI_ACCESS_DENIED			: TEfiStatus = UInt64((1 shl 63) or 15);
	EFI_NO_RESPONSE				: TEfiStatus = UInt64((1 shl 63) or 16);
	EFI_NO_MAPPING				: TEfiStatus = UInt64((1 shl 63) or 17);
	EFI_TIMEOUT					: TEfiStatus = UInt64((1 shl 63) or 18);
	EFI_NOT_STARTED				: TEfiStatus = UInt64((1 shl 63) or 19);
	EFI_ALREADY_STARTED			: TEfiStatus = UInt64((1 shl 63) or 20);
	EFI_ABORTED					: TEfiStatus = UInt64((1 shl 63) or 21);
	EFI_ICMP_ERROR				: TEfiStatus = UInt64((1 shl 63) or 22);
	EFI_TFTP_ERROR				: TEfiStatus = UInt64((1 shl 63) or 23);
	EFI_PROTOCOL_ERROR			: TEfiStatus = UInt64((1 shl 63) or 24);
	EFI_INCOMPATIBLE_VERSION	: TEfiStatus = UInt64((1 shl 63) or 25);
	EFI_SECURITY_VIOLATION		: TEfiStatus = UInt64((1 shl 63) or 26);
	EFI_CRC_ERROR				: TEfiStatus = UInt64((1 shl 63) or 27);
	EFI_END_OF_MEDIA			: TEfiStatus = UInt64((1 shl 63) or 28);
	EFI_END_OF_FILE				: TEfiStatus = UInt64((1 shl 63) or 31);
	EFI_INVALID_LANGUAGE		: TEfiStatus = UInt64((1 shl 63) or 32);
	EFI_COMPROMISED_DATA		: TEfiStatus = UInt64((1 shl 63) or 33);
	EFI_IP_ADDRESS_CONFLICT		: TEfiStatus = UInt64((1 shl 63) or 34);
	EFI_HTTP_ERROR				: TEfiStatus = UInt64((1 shl 63) or 35);

	{ EFI_STATUS Warning Codes (High Bit Clear) [Table 237] }
	EFI_WARN_UNKNOWN_GLYPH		: TEfiStatus = 1;
	EFI_WARN_DELETE_FAILURE		: TEfiStatus = 2;
	EFI_WARN_WRITE_FAILURE		: TEfiStatus = 3;
	EFI_WARN_BUFFER_TOO_SMALL	: TEfiStatus = 4;
	EFI_WARN_STALE_DATA			: TEfiStatus = 5;
	EFI_WARN_FILE_SYSTEM		: TEfiStatus = 6;

	{ EFI GUIDs }
	EFI_LOADED_IMAGE_PROTOCOL_GUID			: TEfiGuid = ($A1, $31, $1B, $5B,
														  $62, $95, $d2, $11,
														  $8E, $3F, $00, $A0,
														  $C9, $69, $72, $3B);
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID	: TEfiGuid = ($22, $5b, $4e, $96,
														  $59, $64, $d2, $11,
														  $8e, $39, $00, $a0,
														  $c9, $69, $72, $3b);
	EFI_FILE_INFO_GUID						: TEfiGuid = ($92, $6e, $57, $09,
														  $3f, $6d, $d2, $11,
														  $8e, $39, $00, $a0,
														  $c9, $69, $72, $3b);
	EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID		: TEfiGuid = ($de, $a9, $42, $90,
														  $dc, $23, $38, $4a,
														  $96, $fb, $7a, $de,
														  $d0, $80, $51, $6a);

	{ EFI Open Modes }
	EFI_FILE_MODE_READ		: UInt64 = 1;
	EFI_FILE_MODE_WRITE		: UInt64 = 2;
	EFI_FILE_MODE_CREATE	: UInt64 = UInt64($8000000000000000);

	{ EFI File Attributes }
	EFI_FILE_READ_ONLY	: UInt64 = UInt64($0000000000000001);
	EFI_FILE_HIDDEN		: UInt64 = UInt64($0000000000000002);
	EFI_FILE_SYSTEM		: UInt64 = UInt64($0000000000000004);
	EFI_FILE_RESERVED	: UInt64 = UInt64($0000000000000008);
	EFI_FILE_DIRECTORY	: UInt64 = UInt64($0000000000000010);
	EFI_FILE_ARCHIVE	: UInt64 = UInt64($0000000000000020);
	EFI_FILE_VALID_ATTR	: UInt64 = UInt64($0000000000000037);

{$endif}
