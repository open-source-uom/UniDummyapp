# UniDummyapp (Workshop Notifier — Qt6 C++ App)

A simple Qt6 C++ desktop app for a workshop demo.

## Features

- System tray notification via `QSystemTrayIcon::showMessage()`
- Notification counter displayed in the notification
- Falls back to `QMessageBox` if the system tray is unavailable

## Prerequisites

- Qt 6.x (with Widgets module)
- CMake ≥ 3.16
- A C++17 compiler (GCC, Clang, MSVC)

Install Qt on Ubuntu/Debian:
```bash
sudo apt install qt6-base-dev cmake build-essential
```

Install Qt on Arch:
```bash
sudo pacman -S qt6-base cmake
```

On Windows/macOS, use the [Qt Online Installer](https://www.qt.io/download).

## Build with CMake (recommended)

```bash
cmake -B build -S .
cmake --build build
./build/WorkshopNotifier      # Linux/macOS
build\WorkshopNotifier.exe    # Windows
```

## Project structure

```
qt-workshop-app/
├── CMakeLists.txt       # CMake build
├── main.cpp             # Entry point
├── mainwindow.h         # MainWindow declaration
├── mainwindow.cpp       # MainWindow implementation
└── mainwindow.ui        # Qt Designer UI form
```

## How it works

| Qt class | Role |
|---|---|
| `QMainWindow` | Top-level application window |
| `QSystemTrayIcon` | System tray icon + notification sender |
| `QSystemTrayIcon::showMessage()` | Sends the desktop notification |
| `QMessageBox` | Fallback when tray is not available |
| `QPushButton` (signal `clicked()`) | Triggers `onNotifyClicked()` slot |

The `clicked()` signal of the button is connected to the `onNotifyClicked()` slot directly in the `.ui` file's `<connections>` section, so no manual `connect()` call is needed in code.
