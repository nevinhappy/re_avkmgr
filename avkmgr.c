#include "ntddk.h"
#include "gdata.h"
#include "avkmgr.h"



#pragma warning(disable:4054)



ULONG g_dwMajorVersion= 0;
ULONG g_dwMinorVersion= 0;








//************************************************************************************************************
//	创建作者  :	Tennn
//  修改时间  :  2017/11/25 22:27
//	函数功能  :	驱动入口
//************************************************************************************************************
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  DriverObject , _In_ PUNICODE_STRING RegistryPath) {

	UNICODE_STRING DeviceName={ 0 };
	PDEVICE_OBJECT DeviceObject={ 0 };
	UNREFERENCED_PARAMETER(RegistryPath);

	OSVERSIONINFOEXW os ={ 0 };
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);
	RtlGetVersion((POSVERSIONINFOW)&os);
	if (os.dwMajorVersion < 5 || os.dwMajorVersion == 5 && !os.dwMinorVersion) {
		return 0x0C0000002;
	}
	g_dwMajorVersion = os.dwMajorVersion;
	g_dwMinorVersion = os.dwMinorVersion;
	sub_140001718();
	avk_GetSystemRoutineAddress();
	func9();
	if (g_FunTable.sub_100) {
		g_FunTable.sub_100(sub_140001390 , 0);
	}
	else {
		g_FunTable.sub_F8(sub_14000130C , 0);
	}
	g_FunTable.sub_108(sub_140001414);
	g_FunTable.sub_110(sub_140001608);
	RtlInitUnicodeString(&DeviceName , avk_SystemRoutineName(0x3b));
	IoCreateDevice(DriverObject , 0 , &DeviceName , 0x22u , 0x100u , 0 , &DeviceObject);
	funcc.field_1C = 1;
	avk_IoErrorLog(L"avkmgr.sys successfully loaded" , 0x40070011 , DriverObject);
	return 0;
}


extern AVKMGR_EXPORT NTSTATUS func0(__int64 Exchange) {
	for (int i = 0; i < 4; i++) {
		if (!_InterlockedCompareExchange64((volatile LONG64 *)(&g_FunTable.sub_1F0)[i] , Exchange , 0)) {
			return 0;
		}
	}
	return 0x0C0000001;
}

extern AVKMGR_EXPORT NTSTATUS func1(__int64 Exchange) {
	for (int i = 0; i < 4; i++) {
		if (!_InterlockedCompareExchange64((volatile LONG64 *)(&g_FunTable.sub_210)[i] , Exchange , 0)) {
			return 0;
		}
	}
	return 0x0C0000001;
}

extern AVKMGR_EXPORT NTSTATUS func2(__int64 Exchange) {
	for (int i = 0; i < 4; i++) {
		if (!_InterlockedCompareExchange64((volatile LONG64 *)(&g_FunTable.sub_230)[i] , Exchange , 0)) {
			return 0;
		}
	}
	return 0x0C0000001;
}

extern AVKMGR_EXPORT NTSTATUS func3(__int64 Exchange) {
	for (int i = 0; i < 4; i++) {
		if (!_InterlockedCompareExchange64((volatile LONG64 *)(&g_FunTable.sub_250)[i] , Exchange , 0)) {
			return 0;
		}
	}
	return 0x0C0000001;
}


extern AVKMGR_EXPORT NTSTATUS func4(__int64 Exchange) {
	for (int i = 0; i < 4; i++) {
		if (Exchange == _InterlockedCompareExchange64((volatile LONG64 *)(&g_FunTable.sub_1F0)[i] , 0 , Exchange)) {
			return 0;
		}
	}
	return 0x0C0000001;
}

extern AVKMGR_EXPORT NTSTATUS func5(__int64 Exchange) {
	for (int i = 0; i < 4; i++) {
		if (!_InterlockedCompareExchange64((volatile LONG64 *)(&g_FunTable.sub_210)[i] , Exchange , 0)) {
			return 0;
		}
	}
	return 0x0C0000001;
}


extern AVKMGR_EXPORT NTSTATUS func6(__int64 Exchange) {
	for (int i = 0; i < 4; i++) {
		if (Exchange == _InterlockedCompareExchange64((volatile LONG64 *)(&g_FunTable.sub_230)[i] , 0 , Exchange)) {
			return 0;
		}
	}
	return 0x0C0000001;
}

extern AVKMGR_EXPORT NTSTATUS func7(__int64 Exchange) {
	for (int i = 0; i < 4; i++) {
		if (Exchange == _InterlockedCompareExchange64((volatile LONG64 *)(&g_FunTable.sub_250)[i] , 0 , Exchange)) {
			return 0;
		}
	}
	return 0x0C0000001;
}

extern AVKMGR_EXPORT NTSTATUS func8() {
	return 0;
}

extern AVKMGR_EXPORT NTSTATUS func9() {
	return 0;
}

extern AVKMGR_EXPORT NTSTATUS funca() {
	return 0;
}


void sub_140001718() {
	unsigned short *loc_word_140004024 = (unsigned short *)word_140004024;
	unsigned short *loc_word_140005204 = (unsigned short *)word_140005204;
	sub_14000168C();
	for (int i = 0 , j = 0; i < 0x6d; i++) {
		g_SystemRoutineName[i] = loc_word_140004024;
		for (j = 0; loc_word_140004024[j]; j++);
		loc_word_140004024 = &loc_word_140004024[j];
	}
	dword_140004020 = 1;
	for (int i = 0 , j = 0; i < 0x2a; i++) {
		qword_140005860[i] = loc_word_140005204;
		for (j = 0; loc_word_140005204[j]; j++);
		loc_word_140005204 = &loc_word_140005204[j];
	}
	dword_140005200 = 1;
}

void avk_GetSystemRoutineAddress() {
	UNICODE_STRING SystemRoutineName={ 0 };
	int FunNumber[] ={
		6, 7, 8, 9,
		0xa, 2, 3, 5,
		0xc, 0xd,
		0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20,
		4, 0x21, 0x22, 0x23,
		0x24, 0x25, 0x26,1 ,
		0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
		0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, };
	if (g_dwMajorVersion < 6) {
		g_FunTable.field_0 = 0;
		g_FunTable.field_10 = 0;
		g_FunTable.field_18 = 0;
	}
	for (int i = 0; i < 0x38; i++) {
		if (!(&g_FunTable.field_0)[i]) {
			RtlInitUnicodeString(&SystemRoutineName , avk_SystemRoutineName(FunNumber[i]));
			(&g_FunTable.field_0)[i] = MmGetSystemRoutineAddress(&SystemRoutineName);
		}
	}
	if (g_dwMajorVersion < 6) {
		g_FunTable.field_0 = 0;
		g_FunTable.field_10 = 0;
		g_FunTable.field_18 = 0;
	}
}

void* sub_140001390(void *a1 , void *a2 , void *a3) {
	if (g_FunTable.sub_1F0) {
		g_FunTable.sub_1F0();
	}
	for (int i = 0; i < 3; i++) {
		g_FunTable.sub_1F8[i](a1 , a2 , a3);
	}
	return &g_FunTable.sub_210;
}

void* sub_14000130C(void *a1 , void *a2 , void *a3) {
	if (g_FunTable.sub_210) {
		g_FunTable.sub_210();
	}
	for (int i = 0; i < 3; i++) {
		g_FunTable.sub_218[i](a1 , a2 , a3);
	}
	return &g_FunTable.sub_230;
}

void* sub_140001414(void *a1 , void *a2 , void *a3) {
	if (g_FunTable.sub_230) {
		g_FunTable.sub_230();
	}
	for (int i = 0; i < 3; i++) {
		g_FunTable.sub_238[i](a1 , a2 , a3);
	}
	return &g_FunTable.sub_250;
}

void* sub_140001608(void *a1 , void *a2 , void *a3) {
	if (g_FunTable.sub_250) {
		g_FunTable.sub_250();
	}
	for (int i = 0; i < 3; i++) {
		g_FunTable.sub_258[i](a1 , a2 , a3);
	}
	return &g_FunTable.sub_270;
}

WCHAR * avk_SystemRoutineName(int FunNumber) {
	if (FunNumber > 0x6d || !dword_140004020) {
		return 0;
	}
	return g_SystemRoutineName[FunNumber];
}

void avk_IoErrorLog(WCHAR *a1 , int a2 , PDRIVER_OBJECT DriverObject) {
	struct ERRORLOGENTRY {
		int field_0;
		int field_4;
		__int16 field_8;
		__int16 field_A;
		int field_C;
		int field_10;
		__unaligned __declspec(align(1)) __int64 field_14;
		int field_1C;
		__int64 field_20;
		__int64 field_28;
		__int64 field_30;
		char field_38[184];
	}*pErrorLogEntry;
	UNICODE_STRING ustring ={ 0 };
	RtlInitUnicodeString(&ustring , a1);
	UCHAR EntrySize = (UCHAR)(ustring.Length + 0x32);
	if (EntrySize > 0xf0) {
		return;
	}
	pErrorLogEntry  = IoAllocateErrorLogEntry(DriverObject , EntrySize);
	if (!pErrorLogEntry) {
		return;
	}
	pErrorLogEntry->field_C = a2;
	pErrorLogEntry->field_14 = 0;
	pErrorLogEntry->field_0 = 0;
	pErrorLogEntry->field_10 = 0;
	pErrorLogEntry->field_4 = 0x300001;
	pErrorLogEntry->field_8 = 0;
	pErrorLogEntry->field_1C = 0;
	memmove(&pErrorLogEntry->field_30 , ustring.Buffer , ustring.Length);
	*(USHORT *)((UCHAR *)pErrorLogEntry->field_30 + ustring.Length) = 0;
	IoWriteErrorLogEntry(pErrorLogEntry);
}

void sub_14000168C() {
	int i = 0;
	short data = 0x57a9;
	unsigned short *loc_word_140004024 = (unsigned short *)word_140004024;
	unsigned short *loc_word_140005204 = (unsigned short *)word_140005204;
	for (; loc_word_140004024[i] != 0x57a9 || loc_word_140004024[i + 1] != 0x57a9; i++ , data += 0x307) {
		loc_word_140004024[i] ^= data;
	}
	loc_word_140004024[i] = 0;
	for (i = 0 , data = 0x57a9; loc_word_140005204[i] != 0x57a9 || loc_word_140005204[i + 1] != 0x57a9; i++) {
		loc_word_140005204[i] ^= data;
	}
	loc_word_140005204[i] = 0;
}
