#include <windows.h>
#include "ProcessOptions.h"


std::vector<ProcessInfo> getProcessList()
{
    std::vector<ProcessInfo> processes;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
        return processes;

    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(snapshot, &entry))
    {
        do
        {
            ProcessInfo info;
            info.pid = entry.th32ProcessID;
            info.parentPid = entry.th32ParentProcessID;
            info.name = entry.szExeFile;
            info.memoryUsage = 0;

            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, info.pid);
            if (hProcess)
            {
                PROCESS_MEMORY_COUNTERS pmc;
                if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
                    info.memoryUsage = pmc.WorkingSetSize;

            }
            CloseHandle(hProcess);

            processes.push_back(info);
        } while (Process32Next(snapshot, &entry));

    }
    CloseHandle(snapshot);
    return processes;
}