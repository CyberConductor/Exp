#pragma once
#include <windows.h>
#include <vector>
#include <TlHelp32.h>
#include <Psapi.h>
struct ThreadInfo
{
	DWORD threadID;
	DWORD ownerPID;
};
std::vector <ThreadInfo> getThreadsProcesses(DWORD pid);