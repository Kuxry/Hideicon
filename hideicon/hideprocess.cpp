//#include <Windows.h>
//#include <ntstatus.h>
//#include <winternl.h>
//#include <iostream>
//
//// 如果 winternl.h 中没有定义 ProcessBreakOnTermination，可以手动定义
//#ifndef ProcessBreakOnTermination
//#define ProcessBreakOnTermination (PROCESS_INFORMATION_CLASS)29
//#endif
//
//typedef NTSTATUS(WINAPI* pNtSetInformationProcess)(
//    HANDLE,
//    PROCESS_INFORMATION_CLASS,
//    PVOID,
//    ULONG
//    );
//
//int HideProcess(DWORD processId) {
//    HMODULE hNtdll = LoadLibraryA("ntdll.dll");
//    if (!hNtdll) return 1;
//
//    pNtSetInformationProcess NtSetInformationProcess =
//        (pNtSetInformationProcess)GetProcAddress(hNtdll, "NtSetInformationProcess");
//
//    if (!NtSetInformationProcess) {
//        FreeLibrary(hNtdll);
//        return 1;
//    }
//
//    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
//    if (!hProcess) {
//        FreeLibrary(hNtdll);
//        return 1;
//    }
//
//    ULONG BreakOnTermination = 1;
//    NTSTATUS status = NtSetInformationProcess(hProcess, ProcessBreakOnTermination, &BreakOnTermination, sizeof(BreakOnTermination));
//
//    CloseHandle(hProcess);
//    FreeLibrary(hNtdll);
//
//    if (status == 0) {
//        return 0;  // 成功
//    }
//    else {
//        return 1;  // 失败
//    }
//}
//
//int main() {
//    DWORD processId = 17324;  // 替换为你想隐藏的进程ID
//    if (HideProcess(processId) == 0) {
//        std::cout << "进程已隐藏\n";
//    }
//    else {
//        std::cout << "无法隐藏进程\n";
//    }
//    return 0;
//}
