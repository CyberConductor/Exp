#pragma once
#include <string>
#include <Windows.h>
struct ProcessInfo
{
    DWORD pid;
    DWORD parentPid;
    std::wstring name;
    SIZE_T memoryUsage;
};