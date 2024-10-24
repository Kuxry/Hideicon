#include <windows.h>
#include <shellapi.h>
#include <iostream>

int main() {
    // 设置 NOTIFYICONDATA 结构体以恢复图标
    NOTIFYICONDATA nid = {};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = FindWindow(NULL, L"Splashtop® Streamer");  // 确保 hWnd 是你的应用窗口句柄
    nid.uID = 194;  // 使用你要恢复的托盘图标的 uID
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // 这里你可以加载原来的图标句柄
    nid.uCallbackMessage = WM_USER + 1;  // 你定义的回调消息
    wcscpy_s(nid.szTip, L"恢复的托盘图标提示");  // 可选的提示文本

    // 恢复托盘图标
    if (Shell_NotifyIcon(NIM_ADD, &nid)) {
        std::cout << "托盘图标已成功恢复" << std::endl;
    }
    else {
        std::cerr << "托盘图标恢复失败" << std::endl;
    }

    return 0;
}
