#include <stdio.h>
#include <Windows.h>
#include <winbase.h>
#include <tchar.h>
#include <strsafe.h>
#include <stdint.h>
#include <iostream>


/* Thanks to the Equation Group, NSA TAO  */
/* Turning this into an application called ZeroDisk at $25 a pop to erase drives to the DoD standard */
/* Shout out to David Taylor Irvine AO Director-General Australian Security Intelligence Organisation */


/*					   */
/* Charles Thomas Wallace Truscott Watters */
/*					   */
/*					   */

using namespace std;

int main(void) {
	void * null_pointer;
	HANDLE hdisk = CreateFileW(L"\\\\.\\F:", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (hdisk == INVALID_HANDLE_VALUE) {
		printf("CreateFile failed, sorry ..\n");
		printf("%d\n", GetLastError());
	} 
	printf("Calculating size of disk\n");
	
	/* position.LowPart = 0; */
	/* position.HighPart = 4096; */
	PLARGE_INTEGER position_two;
	PLARGE_INTEGER disk_size;
	BOOL find_size = GetFileSizeEx(hdisk, disk_size);
	std::cout << (long long int)disk_size << endl;

	printf("Enter the amount of sectors to scan\n");
	printf("e.g. 10, 20, 30 (an integer value)\n");
	int sectors_to_scan;
	scanf("%d", &sectors_to_scan);
	int p;
	for(p = 0; p < sectors_to_scan; ++p) {
		LARGE_INTEGER position = { p * 512 };
		BOOL ok = SetFilePointerEx(hdisk, position, NULL, FILE_BEGIN);
		printf("Scanning sector %I64u\n", position);
		BYTE buffer[512];
		memset(buffer, 0, 512);
		DWORD read;
		ok = WriteFile(hdisk, buffer, 512, NULL, NULL);
	}

	/*printf("%I64u", position);*/;
	int i = 0;
/*	for(; i < 512; ++i) {
		printf("%x\t", buffer[i]);
	}
	Sleep(3000);
	i = 0;
	for(; i < 1; ++i) {
		printf("%x", buffer[i]);
	}*/
	CloseHandle(hdisk);
	return 0;
}