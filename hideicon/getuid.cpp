//#include <windows.h>
//#include <shellapi.h>
//#include <iostream>
//#include <fstream>
//
//// ���ڱ������ڵĻص�����
//BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
//    DWORD processId;
//    GetWindowThreadProcessId(hwnd, &processId);
//
//    if (processId == (DWORD)lParam) {  // ����Ƿ���Ŀ�����
//        std::ofstream logFile("log_id.txt", std::ios::app);
//        logFile << "�ҵ����ڣ����: " << hwnd << std::endl;
//
//        NOTIFYICONDATA nid = {};
//        nid.cbSize = sizeof(NOTIFYICONDATA);
//        nid.hWnd = hwnd;
//
//        // ������� uID ����ɾ������ͼ��
//        for (UINT uID = 0; uID < 10000; ++uID) {
//            nid.uID = uID;
//            if (Shell_NotifyIcon(NIM_DELETE, &nid)) {
//                logFile << "�ɹ�ɾ������ͼ�꣬uID: " << uID << std::endl;
//                logFile.close();
//                return FALSE;  // �ҵ���ֹͣ����
//            }
//        }
//
//        logFile.close();
//    }
//    return TRUE;  // ����������������
//}
//
//int main() {
//    // ���ļ���¼��־������������ܱ��ض�������
//    std::ofstream logFile("log.txt");
//    std::streambuf* coutBuf = std::cout.rdbuf();  // �����׼���������
//    std::streambuf* cerrBuf = std::cerr.rdbuf();  // �����׼���󻺳���
//
//    std::cout.rdbuf(logFile.rdbuf());  // �ض��� std::cout ���ļ�
//    std::cerr.rdbuf(logFile.rdbuf());  // �ض��� std::cerr ���ļ�
//
//    DWORD targetProcessId = 17324;  // �滻ΪĿ�����ID
//
//    // ö�����д��ڣ���������Ŀ����̵Ĵ���
//    EnumWindows(EnumWindowsProc, (LPARAM)targetProcessId);
//
//    // �ָ���׼����ͱ�׼������
//    std::cout.rdbuf(coutBuf);
//    std::cerr.rdbuf(cerrBuf);
//
//    logFile.close();
//    return 0;
//}
