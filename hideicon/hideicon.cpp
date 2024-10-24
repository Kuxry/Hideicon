//#include <windows.h>
//#include <shellapi.h>
//#include <iostream>
//#include <fstream>
//
//BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam) {
//    DWORD processId;
//    GetWindowThreadProcessId(hwnd, &processId);  // 获取子窗口所属的进程ID
//
//    if (processId == (DWORD)lParam) {  // 检查是否是目标进程
//        NOTIFYICONDATA nid = {};
//        nid.cbSize = sizeof(NOTIFYICONDATA);
//        nid.hWnd = hwnd;
//        nid.uID = 194; // 假设托盘图标的 uID 为 1，可以修改
//
//        if (Shell_NotifyIcon(NIM_DELETE, &nid)) {
//            std::cout << "托盘图标成功删除" << std::endl;
//            return FALSE;  // 停止遍历
//        }
//    }
//    return TRUE;  // 继续遍历
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
//    const wchar_t* windowTitle = L"Splashtop® Streamer"; // 替换为实际窗口标题
//
//    // 尝试找到目标窗口
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
//    // 找到托盘窗口
//    HWND trayWnd = FindWindow(L"Shell_TrayWnd", NULL);
//    if (trayWnd == NULL) {
//        std::cerr << "未找到系统托盘窗口" << std::endl;
//        return 1;
//    }
//
//    // 遍历托盘子窗口，删除属于目标进程的托盘图标
//    EnumChildWindows(trayWnd, EnumChildProc, (LPARAM)processId);
//
//    // 恢复标准输出和标准错误流
//    std::cout.rdbuf(coutBuf);
//    std::cerr.rdbuf(cerrBuf);
//
//    logFile.close();
//    return 0;
//}
