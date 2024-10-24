//#include <windows.h>
//#include <shellapi.h>
//#include <iostream>
//#include <fstream>
//
//BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
//    DWORD processId;
//    GetWindowThreadProcessId(hwnd, &processId);
//
//    if (processId == (DWORD)lParam) {  // 检查是否是目标进程
//        std::ofstream logFile("log_id.txt", std::ios::app);
//        logFile << "找到窗口，句柄: " << hwnd << std::endl;
//
//        NOTIFYICONDATA nid = {};
//        nid.cbSize = sizeof(NOTIFYICONDATA);
//        nid.hWnd = hwnd;
//
//        // 遍历多个 uID 尝试删除托盘图标
//        for (UINT uID = 0; uID < 1000; ++uID) {
//            nid.uID = uID;
//            if (Shell_NotifyIcon(NIM_DELETE, &nid)) {
//                logFile << "成功删除托盘图标，uID: " << uID << std::endl;
//                logFile.close();
//                return FALSE;  // 找到后停止遍历
//            }
//        }
//
//        logFile.close();
//    }
//    return TRUE;  // 继续遍历其他窗口
//}
//
//int main() {
//    // 打开文件记录日志
//    std::ofstream logFile("log.txt");
//    std::streambuf* coutBuf = std::cout.rdbuf();  // 保存标准输出缓冲区
//    std::streambuf* cerrBuf = std::cerr.rdbuf();  // 保存标准错误缓冲区
//
//    std::cout.rdbuf(logFile.rdbuf());  // 重定向 std::cout 到文件
//    std::cerr.rdbuf(logFile.rdbuf());  // 重定向 std::cerr 到文件
//
//    // 通过窗口标题找到窗口句柄
//    const wchar_t* windowTitle = L"Splashtop® Streamer";  // 替换为实际窗口标题
//    HWND hWnd = FindWindow(NULL, windowTitle);
//    if (hWnd == NULL) {
//        std::cerr << "未找到窗口: " << windowTitle << std::endl;
//        std::cout.rdbuf(coutBuf);  // 恢复标准输出
//        std::cerr.rdbuf(cerrBuf);  // 恢复标准错误
//        logFile.close();
//        return 1;
//    }
//    else {
//        std::cout << "找到窗口: " << windowTitle << "，句柄: " << hWnd << std::endl;
//    }
//
//    // 获取窗口的进程ID
//    DWORD processId;
//    GetWindowThreadProcessId(hWnd, &processId);
//    std::cout << "窗口所属进程ID: " << processId << std::endl;
//
//    // 枚举所有窗口，查找属于目标进程的窗口并删除托盘图标
//    EnumWindows(EnumWindowsProc, (LPARAM)processId);
//
//    // 恢复标准输出和标准错误流
//    std::cout.rdbuf(coutBuf);
//    std::cerr.rdbuf(cerrBuf);
//
//    logFile.close();
//    return 0;
//}
