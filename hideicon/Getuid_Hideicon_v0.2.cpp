//#include <windows.h>
//#include <shellapi.h>
//#include <iostream>
//#include <fstream>
//#include <iomanip>   // For std::hex
//#include <string>
//#include <locale>
//
//// 回调函数，用于枚举窗口并删除托盘图标
//BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
//    DWORD processId;
//    GetWindowThreadProcessId(hwnd, &processId);
//
//    if (processId == static_cast<DWORD>(lParam)) {  // 检查是否属于目标进程
//        std::wofstream logIdFile("log_id.txt", std::ios::app);
//        if (!logIdFile.is_open()) {
//            return TRUE;  // 无法打开日志文件，继续枚举
//        }
//
//        // 将 HWND 转换为整数并以十六进制格式记录
//        logIdFile << L"Found window, handle: 0x"
//            << std::hex << reinterpret_cast<uintptr_t>(hwnd) << std::endl;
//
//        NOTIFYICONDATA nid = {};
//        nid.cbSize = sizeof(NOTIFYICONDATA);
//        nid.hWnd = hwnd;
//
//        // 尝试删除托盘图标
//        for (UINT uID = 0; uID < 1000; ++uID) {
//            nid.uID = uID;
//            if (Shell_NotifyIcon(NIM_DELETE, &nid)) {
//                logIdFile << L"Successfully deleted tray icon, uID: " << uID << std::endl;
//                logIdFile.close();
//                return FALSE;  // 删除成功，停止枚举
//            }
//        }
//
//        logIdFile.close();
//    }
//    return TRUE;  // 继续枚举其他窗口
//}
//
//// 函数：隐藏指定应用程序的托盘图标
//void HideTrayIconForApp(const std::wstring& windowTitle) {
//    // 打开日志文件
//    std::wofstream logFile("log.txt");
//    if (!logFile.is_open()) {
//        std::wcerr << L"Failed to open log.txt for writing." << std::endl;
//        return;
//    }
//
//    // 设置区域设置为系统默认
//    logFile.imbue(std::locale(""));
//
//    // 重定向 std::wcout 和 std::wcerr 到日志文件
//    std::wstreambuf* wcoutBuf = std::wcout.rdbuf();
//    std::wstreambuf* wcerrBuf = std::wcerr.rdbuf();
//    std::wcout.rdbuf(logFile.rdbuf());
//    std::wcerr.rdbuf(logFile.rdbuf());
//
//    // 诊断：记录接收到的窗口标题的 Unicode 代码点
//    logFile << L"Received window title: ";
//    for (wchar_t ch : windowTitle) {
//        logFile << std::hex << std::setw(4) << std::setfill(L'0') << static_cast<int>(ch) << L' ';
//    }
//    logFile << std::endl;
//
//    // 通过窗口标题查找窗口句柄
//    HWND hWnd = FindWindowW(NULL, windowTitle.c_str());
//    if (hWnd == NULL) {
//        std::wcerr << L"Window not found: " << windowTitle << std::endl;
//        // 恢复标准输出和错误流
//        std::wcout.rdbuf(wcoutBuf);
//        std::wcerr.rdbuf(wcerrBuf);
//        logFile.close();
//        return;
//    }
//    else {
//        // 将 HWND 转换为整数并以十六进制格式记录
//        std::wcout << L"Found window: " << windowTitle << L", handle: 0x"
//            << std::hex << reinterpret_cast<uintptr_t>(hWnd) << std::endl;
//    }
//
//    // 获取窗口的进程 ID
//    DWORD processId;
//    GetWindowThreadProcessId(hWnd, &processId);
//    std::wcout << L"Process ID: " << processId << std::endl;
//
//    // 枚举所有窗口并删除目标进程的托盘图标
//    EnumWindows(EnumWindowsProc, static_cast<LPARAM>(processId));
//
//    // 恢复标准输出和错误流
//    std::wcout.rdbuf(wcoutBuf);
//    std::wcerr.rdbuf(wcerrBuf);
//
//    logFile.close();
//}
//
//int wmain(int argc, wchar_t* argv[]) {
//    // 设置控制台代码页为 UTF-8
//    SetConsoleOutputCP(CP_UTF8);
//    SetConsoleCP(CP_UTF8);
//
//    // 设置区域设置为系统默认
//    std::wcout.imbue(std::locale(""));
//    std::wcerr.imbue(std::locale(""));
//
//    std::wstring windowTitle;
//
//    if (argc == 2) {
//        windowTitle = argv[1];
//    }
//    else {
//        // 如果没有提供命令行参数，进行交互输入
//        std::wcout << L"Please enter the window title (e.g., Splashtop): ";
//        std::getline(std::wcin, windowTitle);
//    }
//
//    if (!windowTitle.empty()) {
//        HideTrayIconForApp(windowTitle);  // 调用函数隐藏托盘图标
//    }
//    else {
//        std::wcout << L"No window title provided! Exiting program." << std::endl;
//        return 1;
//    }
//
//    return 0;
//}
