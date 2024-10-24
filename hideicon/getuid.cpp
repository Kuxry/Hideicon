//#include <windows.h>
//#include <shellapi.h>
//#include <iostream>
//#include <fstream>
//
//// 用于遍历窗口的回调函数
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
//        for (UINT uID = 0; uID < 10000; ++uID) {
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
//    // 打开文件记录日志，处理输出可能被重定向的情况
//    std::ofstream logFile("log.txt");
//    std::streambuf* coutBuf = std::cout.rdbuf();  // 保存标准输出缓冲区
//    std::streambuf* cerrBuf = std::cerr.rdbuf();  // 保存标准错误缓冲区
//
//    std::cout.rdbuf(logFile.rdbuf());  // 重定向 std::cout 到文件
//    std::cerr.rdbuf(logFile.rdbuf());  // 重定向 std::cerr 到文件
//
//    DWORD targetProcessId = 17324;  // 替换为目标进程ID
//
//    // 枚举所有窗口，查找属于目标进程的窗口
//    EnumWindows(EnumWindowsProc, (LPARAM)targetProcessId);
//
//    // 恢复标准输出和标准错误流
//    std::cout.rdbuf(coutBuf);
//    std::cerr.rdbuf(cerrBuf);
//
//    logFile.close();
//    return 0;
//}
