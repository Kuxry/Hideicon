#include <Windows.h>
#include <ntstatus.h>
#include <winternl.h>
#include <iostream>

// 通过 GetProcAddress 获取 NtSetInformationProcess
typedef NTSTATUS(WINAPI* pNtSetInformationProcess)(
    HANDLE,
    PROCESS_INFORMATION_CLASS,
    PVOID,
    ULONG
    );

int HideProcess(DWORD processId) {
    HMODULE hNtdll = LoadLibraryA("ntdll.dll");
    if (!hNtdll) return 1;

    // 获取 NtSetInformationProcess 函数
    pNtSetInformationProcess NtSetInformationProcess =
        (pNtSetInformationProcess)GetProcAddress(hNtdll, "NtSetInformationProcess");

    if (!NtSetInformationProcess) {
        FreeLibrary(hNtdll);
        return 1;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
    if (!hProcess) {
        FreeLibrary(hNtdll);
        return 1;
    }

    // 设置进程的调试端口 (或者使用其他值)
    ULONG BreakOnTermination = 1;
    NTSTATUS status = NtSetInformationProcess(hProcess, ProcessDebugPort, &BreakOnTermination, sizeof(BreakOnTermination));

    CloseHandle(hProcess);
    FreeLibrary(hNtdll);

    if (status == 0) {
        return 0;  // 成功
    }
    else {
        return 1;  // 失败
    }
}

int main() {
    DWORD processId = 17324;  // 替换为你想隐藏的进程ID
    if (HideProcess(processId) == 0) {
        printf("进程已隐藏\n");
    }
    else {
        printf("无法隐藏进程\n");
    }
    return 0;
}
