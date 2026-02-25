# Process & Thread Enumerator

A Windows console application written in modern C++ that enumerates all running processes and their threads using the native Windows API.

## Features

- Lists all running processes with PID, parent PID (PPID), and executable name
- Displays memory usage (Working Set) per process
- Enumerates all threads belonging to each process

## Tech Stack

Built entirely on core WinAPI:

- `CreateToolhelp32Snapshot`
- `Process32First` / `Process32Next`
- `Thread32First` / `Thread32Next`
- `OpenProcess`
- `GetProcessMemoryInfo`

## Getting Started

### Prerequisites

- Windows OS
- Visual Studio or any C++ compiler with WinAPI support (e.g. MinGW)

### Build

```bash
# With MSVC
cl /EHsc main.cpp /link psapi.lib

# Or open the project in Visual Studio and build normally
```

### Run

```bash
ProcessEnumerator.exe
```

## Roadmap

This project is designed to grow into a lightweight EDR-style process monitoring framework. Planned features include:

- Real-time monitoring with periodic refresh and delta detection (new/terminated processes)
- CPU usage calculation per process
- Extended memory analysis
- Thread state and priority inspection
- Module and DLL enumeration per process
- Handle enumeration
- Privilege and integrity level inspection
- Structured logging with JSON/CSV export
- Integration of low-level NT API calls
- Basic behavioral monitoring heuristics

## Goals

This project is primarily a learning exercise in:

- Windows Internals fundamentals
- Process and thread lifecycle management
- System-level programming with WinAPI and NT APIs
- Defensive security tooling design
- Multi-file C++ project architecture

The long-term objective is to evolve this tool into a solid foundation for understanding how EDR and process monitoring tools work at a low level.
