#ifndef UTILS_H
#define UTILS_H

#include <jni.h>
#include <unistd.h>


typedef unsigned long DWORD;


DWORD libBase = 0;

/**************************************
	ENTER THE GAME's LIB NAME HERE!
***************************************/
const char* libName = "libil2cpp.so";


DWORD get_libBase(const char* libName);
DWORD getRealOffset(DWORD address);

DWORD get_libBase(const char* libName) {
	FILE *fp;
	DWORD addr = 0;
	char filename[32], buffer[1024];
	snprintf(filename, sizeof(filename), "/proc/%d/maps", getpid());
	fp = fopen(filename, "rt");
	if (fp != NULL) {
		while (fgets(buffer, sizeof(buffer), fp)) {
			if (strstr(buffer, libName)) {
				addr = (uintptr_t) strtoul(buffer, NULL, 16);
				break;
			}
		}
		fclose(fp);
	}
	return addr;
}

DWORD getRealOffset(DWORD address) {
	if (libBase == 0) {
		libBase = get_libBase(libName);
	}
	return (libBase + address);
}


#endif
