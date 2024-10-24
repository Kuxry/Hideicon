# Tray Icon Manager


Hiding the tray or desktop icon of an application is an effective way to enhance user experience, ensuring the application continues to run in the background while giving users more control over the look and feel of their desktop.

## Feature：
### 1. Keep the Application Running in the Background
Hiding the icon does not mean the application is closed. The program will continue to perform its tasks in the background, such as file backups, system monitoring, or automatic updates. Users can freely manage their desktop layout without worrying that hiding the icon will affect the program’s functionality. This "visual invisibility" ensures that critical background services remain uninterrupted and stable.

### 2. Personalized Desktop Design
For users who prefer a minimalist or personalized desktop design, hiding unnecessary icons reduces visual clutter and optimizes the desktop appearance. Users can choose which icons to display and which to hide based on their preferences, creating a clean and organized workspace that enhances both enjoyment and productivity.

## Prerequisites

- **Operating System**: Windows
- **Development Environment**: Visual Studio (or any C++ IDE supporting Windows development)
- **Tools**: 
  - `Spy++` (optional) for identifying window handles and process information.
  - Administrative privileges may be required for operations on certain system tray icons.

## Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/Kuxry/tray-icon-manager.git
    ```

2. **Open the project** in your preferred C++ IDE (e.g., Visual Studio).
   
3. **Build the project**:
    - Open the solution file in Visual Studio.
    - Build the project using the appropriate configuration (Debug or Release).
    
4. **Run the application**:
    - Ensure the application is run with **administrator privileges** for full functionality, especially when interacting with system tray icons that require elevated permissions.

## Usage

1. **Deleting Tray Icons**:
   - The project automatically finds the tray icons associated with a specific window or process by enumerating windows and processes.
   - To delete an icon, it uses `Shell_NotifyIcon(NIM_DELETE)` with the appropriate `hWnd` and `uID`.
   - **Log file**: All actions are logged to a `log.txt` file, including the window handles and `uID` values tried.

2. **Restoring Tray Icons**:
   - Once an icon is deleted, it can be restored by using `Shell_NotifyIcon(NIM_ADD)`, provided that the `hWnd`, `uID`, and other icon-related details (like `hIcon` and `szTip`) are known.

### Example Command

To delete a tray icon for a specific application window:
```bash
EnumWindows() and Shell_NotifyIcon(NIM_DELETE)
 ```
To restore the icon:
```bash
Shell_NotifyIcon(NIM_ADD)
 ```

Example Code
```bash
NOTIFYICONDATA nid = {};
nid.cbSize = sizeof(NOTIFYICONDATA);
nid.hWnd = FindWindow(NULL, L"YourAppWindowTitle");
nid.uID = 194;  // Known uID for the tray icon
nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // Load original or default icon
Shell_NotifyIcon(NIM_ADD, &nid);
 ```


## Troubleshooting

### No tray icons found
Ensure you have provided the correct `uID` and `hWnd` values for the application window. Use tools like **Spy++** to inspect the application's windows and system messages. Incorrect or mismatched `hWnd` and `uID` values will prevent the tray icon from being deleted or modified.

### Permissions issue
Some tray icons may be protected by the system or require elevated permissions. Try running the application as an administrator to ensure the program has the necessary privileges to delete or modify the tray icons.

### uID Mismatch
Ensure the correct `uID` is used for the tray icon. The `uID` is a unique identifier specific to each application's tray icon. Using the wrong `uID` will result in failure to delete or modify the icon. If the `uID` is unknown, iterate over a range of possible `uID` values (e.g., 0-100) to locate the correct one.

---

## Contributing

Feel free to contribute to this project by forking the repository and creating a pull request. Contributions to enhance functionality or fix issues are welcome. Please make sure to include detailed information about the changes and test cases when applicable.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
