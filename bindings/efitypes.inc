// vim: set filetype=pascal :

{ type definitions for interfacing with EFI.
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

{$ifndef EFILIB_EFITYPES_INC}
{$define EFILIB_EFITYPES_INC}

type
	{ Basic Types [Table 6] }
	TBoolean			= Byte;
	TINTN				= Int64;
	TUINTN				= UInt64;
	TEFIGuid			= array [0..15] of Byte;
	TEFIStatus			= TUINTN;
	TEFIHandle			= Pointer;
	TEFIEvent			= Pointer;
	TEFILba				= UInt64;
	TEFITpl				= TUINTN;
	TEFIMacAddress		= array [0..31] of Byte;
	TEFIIPv4Address		= array [0..3] of Byte;
	TEFIIPv6Address		= array [0..15] of Byte;
	TEFIIPAddress		= TEFIIPv6Address;
	TEFIPhysicalAddress	= UInt64;
	TEFIVirtualAddress	= UInt64;
	PEFIHandle			= ^TEFIHandle;
	PEFIGuid			= ^TEFIGuid;
	PEFIEvent			= ^TEFIEvent;
	PBoolean			= ^TBoolean;
	PChar8				= PChar;
	PChar16				= PWideChar;
	PINTN				= ^TINTN;
	PUINTN				= ^TUINTN;
	PPointer			= ^Pointer;
	PPChar8				= ^PChar8;
	PPChar16			= ^PChar16;
	PPEFIHandle			= ^PEFIHandle;
	PPEFIGuid			= ^PEFIGuid;
	PPPEFIGuid			= ^PPEFIGuid;

	{ Enumations }
	TEFIResetType		= (EfiResetCold,
						   EfiResetWarm,
						   EfiResetShutdown);
	TEFIAllocateType	= (AllocateAnyPages,
						   AllocateMaxAddress,
						   AllocateAddress,
						   MaxAllocateType);
	TEFIMemoryType		= (EfiReservedMemoryType,
						   EfiLoaderCode,
						   EfiLoaderData,
						   EfiBootServicesCode,
						   EfiBootServicesData,
						   EfiRuntimeServicesCode,
						   EfiRuntimeServicesData,
						   EfiConventionalMemory,
						   EfiUnusableMemory,
						   EfiACPIReclaimMemory,
						   EfiACPIMemoryNVS,
						   EfiMemoryMappedIO,
						   EfiMemoryMappedIOPortSpace,
						   EfiPalCode,
						   EfiPersistentMemory,
						   EfiMaxMemoryType);
	TEFIInterfaceType	= (EfiNativeInterface);
	TEFILocateSearchType= (AllHandles,
						   ByRegisterNotify,
						   ByProtocol);
	TEFITimerDelay		= (TimerCancel,
						   TimerPeriodic,
						   TiemrRelative);
	TEFIGraphicsPixelFormat =
						  (PixelRedGreenBlueReserved8BitPerColor,
						   PixelBlueGreenRedReserved8BitPerColor,
						   PixelBitMask,
						   PixelBltOnly,
						   PixelFormatMax);
	TEFIGraphicsOutputBltOperation =
						  (EfiBltVideoFill,
						   EfiBltVideoToBltBuffer,
						   EfiBltBufferToVideo,
						   EfiBltVideoToVideo,
						   EfiGraphicsOutputBltOperationMax);

{$packrecords c}

	PEFISimpleTextInputProtocol			= ^TEFISimpleTextInputProtocol;
	PEFIInputKey						= ^TEFIInputKey;
	PEFISimpleTextOutputProtocol		= ^TEFISimpleTextOutputProtocol;
	PEFITime							= ^TEFITime;
	PEFITimeCapabilities				= ^TEFITimeCapabilities;
	PEFIMemoryDescriptor				= ^TEFIMemoryDescriptor;
	PEFICapsuleHeader					= ^TEFICapsuleHeader;
	PPEFICapsuleHeader					= ^PEFICapsuleHeader;
	PEFIPhysicalAddress					= ^TEFIPhysicalAddress;
	PEFIDevicePathProtocol				= ^TEFIDevicePathProtocol;
	PPEFIDevicePathProtocol				= ^PEFIDevicePathProtocol;
	PEFIOpenProtocolInformationEntry	= ^TEFIOpenProtocolInformationEntry;
	PPEFIOpenProtocolInformationEntry	= ^PEFIOpenProtocolInformationEntry;
	PEFIResetType						= ^TEFIResetType;
	PEFIFileProtocol					= ^TEFIFileProtocol;
	PEFISimpleFileSystemProtocol		= ^TEFISimpleFileSystemProtocol;
	PEFIFileHandle						= PEFIFileProtocol;
	PPEFIFileProtocol					= ^PEFIFileProtocol;
	PEFIFileInfo						= ^TEFIFileInfo;
	PEFIDevicePath						= ^TEFIDevicePath;
	PEFILoadedImageProtocol				= ^TEFILoadedImageProtocol;
	PEFIGraphicsOutputBltPixel			= ^TEFIGraphicsOutputBltPixel;
	PEFIGraphicsOutputModeInformation	= ^TEFIGraphicsOutputModeInformation;
	PPEFIGraphicsOutputModeInformation	= ^PEFIGraphicsOutputModeInformation;
	PEFIGraphicsOutputProtocolMode		= ^TEFIGraphicsOutputProtocolMode;
	PEFIGraphicsOutputProtocol			= ^TEFIGraphicsOutputProtocol;
	PEFIRuntimeServices					= ^TEFIRuntimeServices;
	PEFIConfigurationTable				= ^TEFIConfigurationTable;
	PEFIBootServices					= ^TEFIBootServices;
	PEFISystemTable						= ^TEFISystemTable;

	{ procedural types }

	TEFIInputReset =
		function(
			This: PEFISimpleTextInputProtocol;
			ExtendedVerification: TBoolean
		): TEFIStatus; MS_ABI_CDecl;

	TEFIInputReadKey =
		function(
			This: PEFISimpleTextInputProtocol;
			Key: PEFIInputKey
		): TEFIStatus; MS_ABI_CDecl;

	TEFITextReset = TEFIInputReset;

	TEFITextString =
		function(
			This: PEFISimpleTextOutputProtocol;
			_String: PChar16
		): TEFIStatus; MS_ABI_CDecl;

	TEFITextTestString = TEFITextString;

	TEFITextQueryMode =
		function(
			This: PEFISimpleTextOutputProtocol;
			ModeNumber: TUINTN;
			Columns: PUINTN;
			Rows: PUINTN):
		TEFIStatus; MS_ABI_CDecl;

	TEFITextSetMode =
		function(
			This: PEFISimpleTextOutputProtocol;
			ModeNumber: TUINTN
		): TEFIStatus; MS_ABI_CDecl;

	TEFITextSetAttribute =
		function(
			This: PEFISimpleTextOutputProtocol;
			Attribute: TUINTN):
		TEFIStatus; MS_ABI_CDecl;

	TEFITextClearScreen =
		function(
			This: PEFISimpleTextOutputProtocol
		): TEFIStatus; MS_ABI_CDecl;

	TEFITextSetCursorPosition =
		function(
			This: PEFISimpleTextOutputProtocol;
			Column: TUINTN;
			Row: TUINTN
		): TEFIStatus; MS_ABI_CDecl;

	TEFITextEnableCursor =
		function(
			This: PEFISimpleTextOutputProtocol;
			Visible: Boolean
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGetTime =
		function(
			Time: PEFITime;
			Capabilities: PEFITimeCapabilities
		): TEFIStatus; MS_ABI_CDecl;

	TEFISetTime =
		function(
			Time: PEFITime
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGetWakeupTime =
		function(
			Enabled: PBoolean;
			Pending: PBoolean;
			Time: PEFITime
		): TEFIStatus; MS_ABI_CDecl;

	TEFISetWakeupTime =
		function(
			Enable: TBoolean;
			Time: PEFITime
		): TEFIStatus; MS_ABI_CDecl;

	TEFISetVirtualAddressMap =
		function(
			MemoryMapSize: TUINTN;
			DescriptorSize: TUINTN;
			DescriptorVersion: UInt32;
			VirtualMap: PEFIMemoryDescriptor
		): TEFIStatus; MS_ABI_CDecl;

	TEFIConvertPointer =
		function(
			DebugDesposition: TUINTN;
			Address: PPointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGetVariable =
		function(
			VariableName: PChar16;
			VendorGuid: PEFIGuid;
			Attributes: PUInt32;
			DataSize: PUINTN;
			Data: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGetNextVariableName =
		function(
			VariableNameSize: PUINTN;
			VariableName: PChar16;
			VendorGuid: PEFIGuid
		): TEFIStatus; MS_ABI_CDecl;

	TEFISetVariable =
		function(
			VariableName: PChar16;
			VendorGuid: PEFIGuid;
			Attributes: UInt32;
			DataSize: TUINTN;
			Data: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGetNextHighMonoCount =
		function(
			HighCount: PUInt32
		): TEFIStatus; MS_ABI_CDecl;

	TEFIResetSystem =
		function(
			ResetType: TEFIResetType;
			ResetStatus: TEFIStatus; DataSize: TUINTN;
			ResetData: PChar16
		): TEFIStatus; MS_ABI_CDecl;

	TEFIUpdateCapsule =
		function(
			CapsuleHeaderArray: PPEFICapsuleHeader;
			CapsuleCount: TUINTN;
			ScatterGatherList: TEFIPhysicalAddress
		): TEFIStatus; MS_ABI_CDecl;

	TEFIQueryCapsuleCapabilities =
		function(
			CapsuleHeaderArray: PPEFICapsuleHeader;
			CapsuleCount: TUINTN;
			MaximumCapsuleSize: PUInt64;
			ResetType: PEFIResetType
		): TEFIStatus; MS_ABI_CDecl;

	TEFIQueryVariableInfo =
		function(
			Attributes: UInt32;
			MaximumVariableStorageSize: PUInt64;
			RemainingVariableStorageSize: PUInt64;
			MaximumVariableSize: PUInt64
		): TEFIStatus; MS_ABI_CDecl;

	TEFIRaiseTPL =
		function(
			NewTpl: TEFITPL
		): TEFITPL; MS_ABI_CDecl;

	TEFIRestoreTPL =
		procedure(
			OldTpl: TEFITPL
		); MS_ABI_CDecl;

	TEFIAllocatePages =
		function(
			_Type: TEFIAllocateType;
			MemoryType: TEFIMemoryType;
			Pages: TUINTN;
			Memory: PEFIPhysicalAddress
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFreePages =
		function(
			Memory: PEFIPhysicalAddress;
			Pages: TUINTN
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGetMemoryMap =
		function(
			MemoryMapSize: PUINTN;
			MemoryMap: PEFIMemoryDescriptor;
			MapKey: PUINTN;
			DescriptorSize: PUINTN;
			DescriptorVersion: PUInt32
		): TEFIStatus; MS_ABI_CDecl;

	TEFIAllocatePool =
		function(
			PoolType: TEFIMemoryType;
			Size: TUINTN;
			Buffer: PPointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFreePool =
		function(
			Buffer: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIEventNotify =
		procedure(
			Event: TEFIEvent;
			Context: Pointer
		); MS_ABI_CDecl;

	TEFICreateEvent =
		function(
			_Type: UInt32;
			NotifyTpl: TEFITPL;
			NotifyFunction: TEFIEventNotify;
			Event: PEFIEvent
		): TEFIStatus; MS_ABI_CDecl;

	TEFISetTimer =
		function(
			Event: TEFIEvent;
			_Type: TEFITimerDelay;
			TriggerTime: UInt64
		): TEFIStatus; MS_ABI_CDecl;

	TEFIWaitForEvent =
		function(
			NumberOfEvents: TUINTN;
			Event: PEFIEvent;
			Index: PUINTN
		): TEFIStatus; MS_ABI_CDecl;

	TEFISignalEvent =
		function(
			Event: TEFIEvent
		): TEFIStatus; MS_ABI_CDecl;

	TEFICloseEvent =
		function(
			Event: TEFIEvent
		): TEFIStatus; MS_ABI_CDecl;

	TEFICheckEvent =
		function(
			Event: TEFIEvent
		): TEFIStatus; MS_ABI_CDecl;

	TEFIInstallProtocolInterface =
		function(
			Handle: TEFIHandle;
			Protocol: PEFIGuid;
			InterfaceType: TEFIInterfaceType;
			_Interface: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIReinstallProtocolInterface =
		function(
			Handle: TEFIHandle;
			Protocol: PEFIGuid;
			OldInterface: Pointer;
			NewInterface: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIUninstallProtocolInterface =
		function(
			Handle: TEFIHandle;
			Protocol: PEFIGuid;
			_Interface: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIHandleProtocol =
		function(
			Handle: TEFIHandle;
			Protocol: PEFIGuid;
			_Interface: PPointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIRegisterProtocolNotify =
		function(
			Protocol: PEFIGuid;
			Event: TEFIEvent;
			Registration: PPointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFILocateHandle =
		function(
			SearchType: TEFILocateSearchType;
			Protocol: PEFIGuid;
			SearchKey: Pointer;
			BufferSize: PUINTN;
			Buffer: PEFIHandle
		): TEFIStatus; MS_ABI_CDecl;

	TEFILocateDevicePath =
		function(
			Protocol: PEFIGuid;
			DevicePath: PPEFIDevicePathProtocol;
			Device: PEFIHandle
		): TEFIStatus; MS_ABI_CDecl;

	TEFIInstallConfigurationTable =
		function(
			Guid: PEFIGuid;
			Table: Pointer
		): TEFIstatus; MS_ABI_CDecl;

	TEFIImageLoad =
		function(
			BootPolicy: TBoolean;
			ParentImageHandle: TEFIHandle;
			DevicePath: PEFIDevicePathProtocol;
			SourceBuffer: Pointer;
			SourceSize: TUINTN;
			ImageHandle: PEFIHandle
		): TEFIStatus; MS_ABI_CDecl;

	TEFIImageStart =
		function(
			ImageHandle: TEFIHandle;
			ExitDataSize: PUINTN;
			ExitData: PPChar16
		): TEFIStatus; MS_ABI_CDecl;

	TEFIExit =
		function(
			ImageHandle: TEFIHandle;
			ExitStatus: TEFIStatus;
			ExitDataSize: TUINTN;
			ExitData: PChar16
		): TEFIStatus; MS_ABI_CDecl;

	TEFIImageUnload =
		function(
			ImageHandle: TEFIHandle
		): TEFIStatus; MS_ABI_CDecl;

	TEFIExitBootServices =
		function(
			ImageHandle: TEFIHandle;
			MapKey: TUINTN
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGetNextMonotonicCount =
		function(
			Count: PUInt64
		): TEFIStatus; MS_ABI_CDecl;

	TEFIStall =
		function(
			Microseconds: TUINTN
		): TEFIStatus; MS_ABI_CDecl;

	TEFISetWatchdogTimer =
		function(
			Timeout: TUINTN;
			WatchdogCode: UInt64;
			DataSize: TUINTN;
			WatchdogData: PChar16
		): TEFIStatus; MS_ABI_CDecl;

	TEFIConnectController =
		function(
			ControllerHandle: TEFIHandle;
			DriverImageHandle: PEFIHandle;
			RemainingDevicePath: PEFIDevicePathProtocol;
			Recursive: TBoolean
		): TEFIStatus; MS_ABI_CDecl;

	TEFIDisconnectController =
		function(
			ControllerHandle:  TEFIHandle;
			DriverImageHandle: TEFIHandle;
			ChildHandle: TEFIHandle
		): TEFIStatus; MS_ABI_CDecl;

	TEFIOpenProtocol =
		function(
			Handle: TEFIHandle;
			Protocol: PEFIGuid;
			_Interface: PPointer;
			AgentHandle: TEFIHandle;
			ControllerHandle: TEFIHandle;
			Attributes: UInt32
		): TEFIStatus; MS_ABI_CDecl;

	TEFICloseProtocol =
		function(
			Handle: TEFIHandle;
			Protocol: PEFIGuid;
			AgentHandle: TEFIHandle;
			ControllerHandle: TEFIHandle
		): TEFIStatus; MS_ABI_CDecl;

	TEFIOpenProtocolInformation =
		function(
			Handle: TEFIHandle;
			Protocol: PEFIGuid;
			EntryBuffer:
			PPEFIOpenProtocolInformationEntry;
			EntryCount: PUINTN
		): TEFIStatus; MS_ABI_CDecl;

	TEFIProtocolsPerHandle =
		function(
			Handle: TEFIHandle;
			ProtocolBuffer: PPPEFIGuid;
			ProtocolBufferCount: PUINTN
		): TEFIStatus; MS_ABI_CDecl;

	TEFILocateHandleBuffer =
		function(
			SearchType: TEFILocateSearchType;
			Protocol: PEFIGuid;
			SearchKey: Pointer;
			NoHandles: PUINTN;
			Buffer: PPEFIHandle
		): TEFIStatus; MS_ABI_CDecl;

	TEFILocateProtocol =
		function(
			Protocol: PEFIGuid;
			Registration: Pointer;
			_Interface: PPointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIInstallMultipleProtocolInterfaces =
		function(
			Handle: PEFIHandle
		): TEFIStatus; MS_ABI_CDecl; varargs;

	TEFIUninstallMultipleProtocolInterfaces =
		function(
			Handle: TEFIHandle
		): TEFIStatus; MS_ABI_CDecl; varargs;

	TEFICalculateCrc32 =
		function(
			Data: Pointer;
			DataSize: PUINTN;
			Crc32: PUInt32
		): TEFIStatus; MS_ABI_CDecl;

	TEFICopyMem =
		procedure(
			Destination: Pointer;
			Source: Pointer;
			Length: TUINTN
		); MS_ABI_CDecl;

	TEFISetMem =
		procedure(
			Buffer: Pointer;
			Size: TUINTN;
			Value: UInt8
		); MS_ABI_CDecl;

	TEFICreateEventEx =
		function(
			_Type: UInt32;
			NotifyTpl: TEFITPL;
			NotifyFunction: TEFIEventNotify;
			NotifyContext: Pointer;
			EventGroup: PEFIGuid;
			Event: PEFIEvent
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileOpen =
		function(
			This: PEFIFileProtocol;
			NewHandle: PPEFIFileProtocol;
			FileName: PChar16;
			OpenMode: UInt64;
			Attributes: UInt64
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileClose =
		function(
			This: PEFIFileProtocol
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileDelete =
		function(
			This: PEFIFileProtocol
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileRead =
		function(
			This: PEFIFileProtocol;
			BufferSize: PUINTN;
			Buffer: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileWrite =
		function(
			This: PEFIFileProtocol;
			BufferSize: PUINTN;
			Buffer: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileGetPosition =
		function(
			This: PEFIFileProtocol;
			Position: PUInt64
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileSetPosition =
		function(
			This: PEFIFileProtocol;
			Position: PUInt64
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileGetInfo =
		function(
			This: PEFIFileProtocol;
			InformationType: PEFIGuid;
			BufferSize: PUINTN;
			Buffer: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileSetInfo =
		function(
			This: PEFIFileProtocol;
			InformationType: PEFIGuid;
			BufferSize: TUINTN;
			Buffer: Pointer
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileFlush =
		function(
			This: PEFIFileProtocol
		): TEFIStatus; MS_ABI_CDecl;

	TEFIFileOpenEx	= Pointer;
	TEFIFileReadEx	= Pointer;
	TEFIFileWriteEx	= Pointer;
	TEFIFileFlushEx	= Pointer;

	TEFISimpleFileSystemProtocolOpenVolume =
		function(
			This: PEFISimpleFileSystemProtocol;
			Root: PPEFIFileProtocol
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGraphicsOutputProtocolQueryMode =
		function(
			This: PEFIGraphicsOutputProtocol;
			ModeNumber: UInt32;
			SizeOfInfo: PUINTN;
			Info: PPEFIGraphicsOutputModeInformation
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGraphicsOutputProtocolSetMode =
		function(
			This: PEFIGraphicsOutputProtocol;
			ModeNumber: UInt32
		): TEFIStatus; MS_ABI_CDecl;

	TEFIGraphicsOutputProtocolBlt =
		function(
			This: PEFIGraphicsOutputProtocol;
			BltBuffer: PEFIGraphicsOutputBltPixel;
			BltOperation: TEFIGraphicsOutputBltOperation;
			SourceX: TUINTN;
			SourceY: TUINTN;
			DestinationX: TUINTN;
			DestinationY: TUINTN;
			Width: TUINTN;
			Height: TUINTN;
			Delta: TUINTN
		): TEFIStatus; MS_ABI_CDecl;

	{ records }

	TEFITableHeader = record
		Signature	: UInt64;
		Revision	: UInt32;
		HeaderSize	: UInt32;
		CRC32		: UInt32;
		Reserved	: UInt32;
	end;

	TEFICapsuleHeader = record
		CapsuleGuid		 : TEFIGuid;
		HeaderSize		 : UInt32;
		Flags			 : UInt32;
		CapsuleImageSize : UInt32;
	end;

	TEFIConfigurationTable = record
		VendorGuid	: TEFIGuid;
		VendorTable	: Pointer;
	end;

	TEFIOpenProtocolInformationEntry = record
		AgentHandle		 : TEFIHandle;
		ControllerHandle : TEFIHandle;
		Attributes		 : UInt32;
		OpenCount		 : UInt32;
	end;

	TEFIDevicePathProtocol = record
		_Type	: UInt8;
		SubType	: UInt8;
		Length	: array [0..1] of UInt8;
	end;

	TEFIMemoryDescriptor = record
		_Type			: TEFIMemoryType;
		PhysicalStart	: TEFIPhysicalAddress;
		VirtualStart	: TEFIVirtualAddress;
		NumberOfPages	: UInt64;
		Attribute		: UInt64;
	end;

	TEFITime = record
		Year		: UInt16; { 1900 – 9999 }
		Month		: UInt8;  { 1 – 12 }
		Day			: UInt8;  { 1 – 31 }
		Hour		: UInt8;  { 0 – 23 }
		Minute		: UInt8;  { 0 – 59 }
		Second		: UInt8;  { 0 – 59 }
		Pad1		: UInt8;
		Nanosecond	: UInt32; { 0 – 999,999,999 }
		TimeZone	: Int16;  { -1440 to 1440 or 2047 }
		Daylight	: UInt8;
		Pad2		: UInt8;
	end;

	TEFITimeCapabilities = record
		Resolution	: UInt32;
		Accuracy	: UInt32;
		SetsToZero	: TBoolean;
	end;

	TEFISimpleTextInputProtocol = record
		Reset			: TEFIInputReset;
		ReadKeyStroke	: TEFIInputReadKey;
		WaitForKey		: TEFIEvent;
	end;

	TEFIInputKey = record
		ScanCode	: UInt16;
		UnicodeChar	: Char16;
	end;

	TSimpleTextOutputMode = record
		MaxMode			: Int32;
		{ current settings }
		Mode			: Int32;
		Attribute		: Int32;
		CursorColumn	: Int32;
		CursorRow		: Int32;
		CursorVisible	: TBoolean;
	end;

	PSimpleTextOutputMode = ^TSimpleTextOutputMode;

	TEFISimpleTextOutputProtocol = record
		Reset				: TEFITextReset;
		OutputString		: TEFITextString;
		TestString			: TEFITextTestString;
		QueryMode			: TEFITextQueryMode;
		SetMode				: TEFITextSetMode;
		SetAttribute		: TEFITextSetAttribute;
		ClearScreen			: TEFITextClearScreen;
		SetCursorPosition	: TEFITextSetCursorPosition;
		EnableCursor		: TEFITextEnableCursor;
		Mode				: PSimpleTextOutputMode;
	end;

	TEFISimpleFileSystemProtocol = record
		Revision	: UInt64;
		OpenVolume	: TEFISimpleFileSystemProtocolOpenVolume;
	end;

	TEFIFileProtocol = record
		Revision	: UInt64;
		Open		: TEFIFileOpen;
		Close		: TEFIFileClose;
		Delete		: TEFIFileDelete;
		Read		: TEFIFileRead;
		Write		: TEFIFileWrite;
		GetPosition	: TEFIFileGetPosition;
		SetPosition	: TEFIFileSetPosition;
		GetInfo		: TEFIFileGetInfo;
		SetInfo		: TEFIFileSetInfo;
		Flush		: TEFIFileFlush;
		OpenEx		: TEFIFileOpenEx;
		ReadEx		: TEFIFileReadEx;
		WriteEx		: TEFIFileWriteEx;
		FlushEx		: TEFIFileFlushEx;
	end;

	TEFIFileInfo = record
		Size				: UInt64;
		FileSize			: UInt64;
		PhysicalSize		: UInt64;
		CreateTime			: TEFITime;
		LastAccessTime		: TEFITime;
		ModificationTime	: TEFITime;
		Attribute			: UInt64;
		{ In C, there is a flexible CHAR16 array member here, you just have to
		  imagine that here :3 }
	end;

	TEFIDevicePath = record
		_Type	: UInt8;
		SubType	: UInt8;
		Length	: array [0..1] of UInt8;
	end;

	TEFILoadedImageProtocol = record
		Revision			: UInt32;
		ParentHandle		: TEFIHandle;
		SystemTable			: PEFISystemTable;
		DeviceHandle		: TEFIHandle;
		FilePath			: TEFIDevicePath;
		Reserved			: Pointer;
		LoadedOptionsSize	: UInt32;
		LoadOptions			: Pointer;
		ImageBase			: Pointer;
		ImageSize			: UInt64;
		ImageCodeType		: TEFIMemoryType;
		ImageDataType		: TEFIMemoryType;
	end;

	TEFIPixelBitmask = record
		RedMask			: UInt8;
		GreenMask		: UInt8;
		BlueMask		: UInt8;
		ReservedMask	: UInt8;
	end;

	TEFIGraphicsOutputBltPixel = record
		Blue		: UInt8;
		Green		: UInt8;
		Red			: UInt8;
		Reserved	: UInt8;
	end;

	TEFIGraphicsOutputModeInformation = record
		Version					: UInt32;
		HorizontalResolution	: UInt32;
		VerticalResolution		: UInt32;
		PixelFormat				: TEFIGraphicsPixelFormat;
		PixelInformation		: TEFIPixelBitmask;
		PixelsPerScanLine		: UInt32;
	end;

	TEFIGraphicsOutputProtocolMode = record
		MaxMode			: UInt32;
		Mode			: UInt32;
		Info			: PEFIGraphicsOutputModeInformation;
		SizeOfInfo		: TUINTN;
		FrameBufferBase	: TEFIPhysicalAddress;
		FrameBufferSize	: TUINTN;
	end;

	TEFIGraphicsOutputProtocol = record
		QueryMode	: TEFIGraphicsOutputProtocolQueryMode;
		SetMode		: TEFIGraphicsOutputProtocolSetMode;
		Blt			: TEFIGraphicsOutputProtocolBlt;
		Mode		: PEFIGraphicsOutputProtocolMode;
	end;

	TEFIRuntimeServices = record
		Hdr							: TEFITableHeader;
		{ Time Services }
		GetTime						: TEFIGetTime;
		SetTime						: TEFISetTime;
		GetWakeupTime				: TEFIGetWakeupTime;
		SetWakeupTime				: TEFISetWakeupTime;
		{ Virtual Memory Services }
		SetVirtualAddressMap		: TEFISetVirtualAddressMap;
		ConvertPointer				: TEFIConvertPointer;
		{ Variable Services }
		GetVariable					: TEFIGetVariable;
		GetNextVariableName			: TEFIGetNextVariableName;
		SetVariable					: TEFISetVariable;
		{ Miscellaneous Services }
		GetNextHighMonotonicCount	: TEFIGetNextHighMonoCount;
		ResetSystem					: TEFIResetSystem;
		{ UEFI 2.0 Capsule Services }
		UpdateCapsule				: TEFIUpdateCapsule;
		QueryCapsuleCapabilities	: TEFIQueryCapsuleCapabilities;
		{ Miscellaneous UEFI 2.0 Service }
		QueryVariableInfo			: TEFIQueryVariableInfo;
	end;

	TEFIBootServices = record
		Hdr									: TEFITableHeader;
		{ Task Priority Services }
		RaiseTPL							: TEFIRaiseTpl;
		RestoreTPL							: TEFIRestoreTpl;
		{ Memory Services }
		AllocatePages						: TEFIAllocatePages;
		FreePages							: TEFIFreePages;
		GetMemoryMap						: TEFIGetMemoryMap;
		AllocatePool						: TEFIAllocatePool;
		FreePool							: TEFIFreePool;
		{ Event & Timer Services }
		CreateEvent							: TEFICreateEvent;
		SetTimer							: TEFISetTimer;
		WaitForEvent						: TEFIWaitForEvent;
		SignalEvent							: TEFISignalEvent;
		CloseEvent							: TEFICloseEvent;
		CheckEvent							: TEFICheckEvent;
		{ Protocol Handler Services }
		InstallProtocolInterface			: TEFIInstallProtocolInterface;
		ReinstallProtocolInterface			: TEFIReinstallProtocolInterface;
		UninstallProtocolInterface			: TEFIUninstallProtocolInterface;
		HandleProtocol						: TEFIHandleProtocol;
		Reserved							: Pointer;
		RegisterProtocolNotify				: TEFIRegisterProtocolNotify;
		LocateHandle						: TEFILocateHandle;
		LocateDevicePath					: TEFILocateDevicePath;
		InstallConfigurationTable			: TEFIInstallConfigurationTable;
		{ Image Services }
		LoadImage							: TEFIImageLoad;
		StartImage							: TEFIImageStart;
		Exit								: TEFIExit;
		UnloadImage							: TEFIImageUnload;
		ExitBootServices					: TEFIExitBootServices;
		{ Miscellaneous Services }
		GetNextMonotonicCount				: TEFIGetNextMonotonicCount;
		Stall								: TEFIStall;
		SetWatchdogTimer					: TEFISetWatchdogTimer;
		{ DriverSupport Services }
		ConnectController					: TEFIConnectController;
		DisconnectController				: TEFIDisconnectController;
		{ Open and Close Protocol Services }
		OpenProtocol						: TEFIOpenProtocol;
		CloseProtocol						: TEFICloseProtocol;
		OpenProtocolInformation				: TEFIOpenProtocolInformation;
		{ Library Services }
		ProtocolsPerHandle					: TEFIProtocolsPerHandle;
		LocateHandleBuffer					: TEFILocateHandleBuffer;
		LocateProtocol						: TEFILocateProtocol;
		InstallMultipleProtocolInterfaces	:
									TEFIInstallMultipleProtocolInterfaces;
		UninstallMultipleProtocolInterfaces	:
									TEFIUninstallMultipleProtocolInterfaces;
		{ 32-bit CRC Services }
		CalculateCrc32						: TEFICalculateCrc32;
		{ Miscellaneous Services }
		CopyMem								: TEFICopyMem;
		SetMem								: TEFISetMem;
		CreateEventEx						: TEFICreateEventEx;
	end;

	TEFISystemTable = record
		Hdr					 : TEFITableHeader;
		FirmwareVendor		 : PChar16;
		FirmwareRevision	 : UInt32;
		ConsoleInHandle		 : TEFIHandle;
		ConIn				 : PEFISimpleTextInputProtocol;
		ConsoleOutHandle	 : TEFIHandle;
		ConOut				 : PEFISimpleTextOutputProtocol;
		StandardErrorHandle	 : TEFIHandle;
		StdErr				 : PEFISimpleTextOutputProtocol;
		RuntimeServices		 : PEFIRuntimeServices;
		BootServices		 : PEFIBootServices;
		NumberOfTableEntries : TUINTN;
		ConfigurationTable	 : PEFIConfigurationTable;
	end;

{$packrecords default}

{$endif}
