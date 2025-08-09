{$mode fpc}
unit system;

interface

const
	CP_ACP     = 0;     // default to ANSI code page
	CP_OEMCP   = 1;     // default to OEM (console) code page
	CP_UTF16   = 1200;  // utf-16
	CP_UTF16BE = 1201;  // unicodeFFFE
	CP_UTF7    = 65000; // utf-7
	CP_UTF8    = 65001; // utf-8
	CP_ASCII   = 20127; // us-ascii
	CP_NONE    = $FFFF; // rawbytestring encoding
type
	Cardinal	= 0..$FFFFFFFF;
	HResult		= Cardinal;
	DWord		= Cardinal;
	Integer		= LongInt;
	PWideChar	= ^WideChar;
	PChar		= ^Char;

	TTypeKind = (
		tkUnknown, tkInteger, tkChar, tkEnumeration, tkFloat, tkSet,
		tkMethod, tkSString, tkLString, tkAString, tkWString, tkVariant,
		tkArray, tkRecord, tkInterface, tkClass, tkObject, tkWChar, tkBool,
		tkInt64, tkQWord, tkDynArray, tkInterfaceRaw, tkProcVar, tkUString,
		tkUChar, tkHelper, tkFile, tkClassRef, tkPointer
	);

	PtrInt	= Int64;
	PtrUInt	= QWord;
	Int8	= ShortInt;
	Int16	= SmallInt;
	Int32	= Longint;
	IntPtr	= PtrInt;
	UInt8	= Byte;
	UInt16	= Word;
	UInt32	= Cardinal;
	UIntPtr	= PtrUInt;
	UInt64	= QWord;
	Char8	= Char;
	Char16	= WideChar;
	PChar8	= ^Char8;
	PChar16	= ^WideChar;
	PInt8	= ^Int8;
	PInt16	= ^Int16;
	PInt32	= ^Int32;
	PUInt8	= ^UInt8;
	PUInt16	= ^UInt16;
	PUInt32	= ^UInt32;
	PUInt64	= ^UInt64;

	UTF8String = type AnsiString(CP_UTF8);
  PAnsiRec = ^TAnsiRec;
  TAnsiRec = Record
    CodePage    : Word;
    ElementSize : Word;
{$ifdef CPU64}	
    { align fields  }
	Dummy       : DWord;
{$endif CPU64}
    Ref         : UInt64;
    Len         : UInt64;
  end;

	jmp_buf = packed record
		rbx, rbp, r12, r13, r14, r15, rsp, rip: QWord;
		{$IFDEF win64}
		rsi, rdi: QWord;
		xmm6, xmm7, xmm8, xmm9, xmm10, xmm11,
		xmm12, xmm13, xmm14, xmm15: record
			m1, m2: QWord;
		end;

		mxcsr: LongWord;
		fpucw: word;
		padding: word;
		{$ENDIF win64}
	end;

	Pjmp_buf	= ^jmp_buf;
	PExceptAddr	= ^TExceptAddr;
	TExceptAddr	= record
		buf: Pjmp_buf;
		next: PExceptAddr;
		{$IFDEF CPU16}
		frametype: SmallInt;
		{$ELSE CPU16}
		frametype: LongInt;
		{$ENDIF CPU16}
	end;

	PGuid	= ^TGuid;
	TGuid	= packed record
		case Integer of
		1:
		(Data1: DWord;
			Data2: word;
			Data3: word;
			Data4: array [0 .. 7] of byte;
		);
		2:
		(D1: DWord;
			D2: word;
			D3: word;
			D4: array [0 .. 7] of byte;
		);
		3:
		(
			{ uuid fields according to RFC4122 }
			time_low			: DWord; // The low field of the timestamp
			time_mid			: word;  // The middle field of the timestamp
			time_hi_and_version	: word;

			{ The high field of the timestamp multiplexed with the
			  version number }
			clock_seq_hi_and_reserved: byte;
			{ The high field of the clock sequence multiplexed with the
			  variant }
			clock_seq_low	: byte; // The low field of the clock sequence
			node			: array [0 .. 5] of byte; { The spatially unique
														node identifier }
		);
	end;

{ --- End of nessesary part --- }

const
	fpc_in_round_real	= 121;
	fpc_in_int_real		= 123;

function Round(d : Double) : Integer; [internproc:fpc_in_round_real];
function Int(d : Double) : Integer; [internproc:fpc_in_int_real];

implementation

end.
