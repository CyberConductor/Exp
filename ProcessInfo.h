#pragma once
#include <string>
#include <Windows.h>
#include "ThreadInfo.h"
struct ProcessInfo
{
    DWORD pid;
    DWORD parentPid;
    std::wstring name;
    SIZE_T memoryUsage;
    std::vector<ThreadInfo> threads;
};