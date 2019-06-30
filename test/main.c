#include <stdio.h>
#include <Windows.h>

typedef void (*FunIpcCallBack)(int hdl, char *argv[], int argc);
typedef int (*FunIpcConnect)(const char* name, FunIpcCallBack cb);
typedef int (*FunIpcCall)(int hdl, char *argv[], int argc);
typedef int (*FunIpcClose)(int hdl);
typedef int (*FunIpcInit)(void);

static FunIpcInit IpcInit;
static FunIpcConnect IpcConnect;
static FunIpcCall IpcCall;
static FunIpcClose IpcClose;

void MyIpcCallBack(int hdl, char *funArgv[], int argc) {
    printf("%d - %s - %d", hdl, funArgv[0], argc);
}

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
    IpcInit();
    int id = IpcConnect("IpcServer", MyIpcCallBack);
    Sleep(1000);

    for(int i = 0; i < 1000; i++) {
        char name[10];
        sprintf(name, "%d", i);
        char *argv[] = {"sendMessage", "a", "c", name};
        int argc = sizeof(argv) / sizeof(argv[0]);
        Sleep(10);
        IpcCall(id, argv, argc);
    }
    printf("press c to continue.");
    while(getchar() != 'c') {
        printf("press c to continue.");
    }
    FreeLibrary(hdl);
    printf("exit now.");
    return 0;
}
