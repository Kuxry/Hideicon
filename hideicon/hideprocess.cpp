//#include <Windows.h>
//#include <ntstatus.h>
//#include <winternl.h>
//#include <iostream>
//
//// ��� winternl.h ��û�ж��� ProcessBreakOnTermination�������ֶ�����
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
//        return 0;  // �ɹ�
//    }
//    else {
//        return 1;  // ʧ��
//    }
//}
//
//int main() {
//    DWORD processId = 17324;  // �滻Ϊ�������صĽ���ID
//    if (HideProcess(processId) == 0) {
//        std::cout << "����������\n";
//    }
//    else {
//        std::cout << "�޷����ؽ���\n";
//    }
//    return 0;
//}
