#include <Windows.h>
#include <ntstatus.h>
#include <winternl.h>
#include <iostream>

// ͨ�� GetProcAddress ��ȡ NtSetInformationProcess
typedef NTSTATUS(WINAPI* pNtSetInformationProcess)(
    HANDLE,
    PROCESS_INFORMATION_CLASS,
    PVOID,
    ULONG
    );

int HideProcess(DWORD processId) {
    HMODULE hNtdll = LoadLibraryA("ntdll.dll");
    if (!hNtdll) return 1;

    // ��ȡ NtSetInformationProcess ����
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

    // ���ý��̵ĵ��Զ˿� (����ʹ������ֵ)
    ULONG BreakOnTermination = 1;
    NTSTATUS status = NtSetInformationProcess(hProcess, ProcessDebugPort, &BreakOnTermination, sizeof(BreakOnTermination));

    CloseHandle(hProcess);
    FreeLibrary(hNtdll);

    if (status == 0) {
        return 0;  // �ɹ�
    }
    else {
        return 1;  // ʧ��
    }
}

int main() {
    DWORD processId = 17324;  // �滻Ϊ�������صĽ���ID
    if (HideProcess(processId) == 0) {
        printf("����������\n");
    }
    else {
        printf("�޷����ؽ���\n");
    }
    return 0;
}
