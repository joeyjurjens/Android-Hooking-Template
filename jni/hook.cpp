#include <jni.h>
//#include <android/log.h>
#include <Substrate/CydiaSubstrate.h>
#include <memory.h>
#include <dlfcn.h>
#include <cstdio>
#include <cstdlib>
#import "Utils.h"

void(*old_Update)(void *instance);
void Update(void *instance) {

    //private readonly Model IDDCHJOHKGC; // 0xC
    void *getToModelClass = *(void**)((uint64_t)instance + 0xC);

    //private int <id>k__BackingField; // 0x60
    int playerID = *(int*)((uint64_t)getToModelClass + 0x60);

    // 1 --> ME, 2--> ENEMY

    if(playerID == 2) {
        // private bool <isDead>k__BackingField; // 0x8C
        *(bool*)((uint64_t)getToModelClass + 0x8C) = true;
    }
}

__attribute__((constructor))
void libhook_main() {

    while(libBase == 0) { 
        libBase = get_libBase(libName); 
        sleep(1); 
    }   
    
    MSHookFunction((void *)getRealOffset(0x12BA798), (void *)Update, (void **) &old_Update);
}
