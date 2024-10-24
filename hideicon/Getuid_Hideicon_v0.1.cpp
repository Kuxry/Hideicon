//#include <windows.h>
//#include <shellapi.h>
//#include <iostream>
//#include <fstream>
//
//// Callback function for enumerating windows
//BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
//    DWORD processId;
//    GetWindowThreadProcessId(hwnd, &processId);
//
//    if (processId == (DWORD)lParam) {  // Check if it's the target process
//        std::ofstream logFile("log_id.txt", std::ios::app);
//        logFile << "Window found, handle: " << hwnd << std::endl;
//
//        NOTIFYICONDATA nid = {};
//        nid.cbSize = sizeof(NOTIFYICONDATA);
//        nid.hWnd = hwnd;
//
//        // Iterate through multiple uIDs to attempt to delete the tray icon
//        for (UINT uID = 0; uID < 1000; ++uID) {
//            nid.uID = uID;
//            if (Shell_NotifyIcon(NIM_DELETE, &nid)) {
//                logFile << "Successfully deleted tray icon, uID: " << uID << std::endl;
//                logFile.close();
//                std::cout << "Successfully deleted tray icon, uID: " << uID << std::endl;
//                return FALSE;  // Stop enumeration after finding
//            }
//        }
//
//        logFile.close();
//    }
//    return TRUE;  // Continue enumerating other windows
//}
//
//int main() {
//    // Open file to record logs
//    std::ofstream logFile("log.txt");
//    std::streambuf* coutBuf = std::cout.rdbuf();  // Save the standard output buffer
//    std::streambuf* cerrBuf = std::cerr.rdbuf();  // Save the standard error buffer
//
//    std::cout.rdbuf(logFile.rdbuf());  // Redirect std::cout to the file
//    std::cerr.rdbuf(logFile.rdbuf());  // Redirect std::cerr to the file
//
//    // Find window handle by window title
//    const wchar_t* windowTitle = L"Splashtop® Streamer";  // Replace with the actual window title
//    HWND hWnd = FindWindow(NULL, windowTitle);
//    if (hWnd == NULL) {
//        std::cerr << "Window not found: " << windowTitle << std::endl;
//        std::cout.rdbuf(coutBuf);  // Restore standard output
//        std::cerr.rdbuf(cerrBuf);  // Restore standard error
//        logFile.close();
//        return 1;
//    }
//    else {
//        std::cout << "Window found: " << windowTitle << ", handle: " << hWnd << std::endl;
//    }
//
//    // Get the process ID of the window
//    DWORD processId;
//    GetWindowThreadProcessId(hWnd, &processId);
//    std::cout << "Process ID of the window: " << processId << std::endl;
//
//    // Enumerate all windows to find windows belonging to the target process and delete tray icons
//    EnumWindows(EnumWindowsProc, (LPARAM)processId);
//
//    // Restore the standard output and standard error streams
//    std::cout.rdbuf(coutBuf);
//    std::cerr.rdbuf(cerrBuf);
//
//    logFile.close();
//    return 0;
//}
