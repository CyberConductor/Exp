#include "ThreadInfo.h"

std::vector <ThreadInfo> getThreadsProcesses(DWORD pid)
{
	std::vector<ThreadInfo> threads;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,0);
	if (snapshot == INVALID_HANDLE_VALUE)
		return threads;
	THREADENTRY32 entry;
	entry.dwSize = sizeof(THREADENTRY32);
	if (Thread32First(snapshot, &entry))
	{
		do
		{
			if (entry.th32OwnerProcessID == pid)
			{
				ThreadInfo info;
				info.threadID = entry.th32ThreadID;
				info.ownerPID = entry.th32OwnerProcessID;
				threads.push_back(info);
			}

		} while (Thread32Next(snapshot, &entry));
	}

	CloseHandle(snapshot);
	return threads;
}