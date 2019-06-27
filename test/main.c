#include <stdio.h>
#include <Windows.h>

typedef void (*FunIpcCallBack)(int hdl, char *funName, char *argv[]);
typedef int (*FunIpcConnect)(const char* name, FunIpcCallBack cb);
typedef int (*FunIpcCall)(int hdl, const char* funName, char *argv[]);
typedef int (*FunIpcClose)(int hdl);
typedef int (*FunIpcInit)(void);

static FunIpcInit IpcInit;
static FunIpcConnect IpcConnect;
static FunIpcCall IpcCall;
static FunIpcClose IpcClose;

int main()
{
    printf("Hello World!\n");
    HMODULE hdl = LoadLibraryA("woipc.dll");
    if(hdl == NULL) {
        printf("Can Not Find WoIpc.dll");
        return 0;
    }
    IpcInit = (FunIpcInit)GetProcAddress(hdl, "IpcInit");
    IpcConnect = (FunIpcConnect)GetProcAddress(hdl, "IpcConnect");
    IpcCall = (FunIpcCall)GetProcAddress(hdl, "IpcCall");
    IpcClose = (FunIpcClose)GetProcAddress(hdl, "IpcClose");
    printf("press c to continue.");
    while(getchar() != 'c') {
        printf("press c to continue.");
    }
    FreeLibrary(hdl);
    printf("exit now.");
    return 0;
}