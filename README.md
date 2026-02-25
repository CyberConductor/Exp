🖥 Process & Thread Enumerator (Windows, C++ / WinAPI)

📌 Overview
This project is a Windows console application written in modern C++ using the native Windows API.
It enumerates all running processes on the system and displays:

Process ID (PID)
Parent Process ID (PPID)
Executable name
Memory usage (Working Set)
All threads belonging to each process
The implementation relies on core WinAPI functions, including:
CreateToolhelp32Snapshot
Process32First / Process32Next
Thread32First / Thread32Next
OpenProcess
GetProcessMemoryInfo

This project is designed primarily for learning and experimentation in the areas of:

Windows Internals fundamentals
Process and thread enumeration
Low-level system programming with WinAPI
Multi-file C++ project architecture

🚀 Future Development
The current version provides foundational process and thread enumeration functionality.
The project is intended to evolve into a more advanced Windows process inspection and monitoring tool.

Planned Enhancements
Real-time monitoring with periodic refresh
Detection of newly created and terminated processes
CPU usage calculation per process
Extended memory analysis
Thread state and priority inspection
Module enumeration, DLL listing per process
Handle enumeration
Basic behavioral monitoring logic
Structured logging system
Export functionality, JSON or CSV
Privilege and integrity level inspection
Integration of low-level NT API calls
Gradual transition toward a lightweight EDR-style monitoring prototype

🎯 Long-Term Goal

The long-term objective of this project is to build a strong understanding of:

Windows Internals
Process and thread management
System-level monitoring techniques
Defensive security tooling design

The tool will progressively evolve from a basic enumerator into a more advanced process inspection and behavioral monitoring framework.
