#include <iostream>
#include "ProcessOptions.h"
#include "ProcessInfo.h"
#include "ThreadInfo.h"
#include "RegDetect.h"

int main()
{
    auto processes = getProcessList();
    for (auto& p : processes)
    {
        p.threads = getThreadsProcesses(p.pid);
        std::wcout << L"\nProcess: " << p.name << std::endl;
        std::wcout << L" | PID: " << p.pid << std::endl;
        std::wcout << L" | Parent PID: " << p.parentPid << std::endl;
        std::wcout<< L" | Memory: " << p.memoryUsage << std::endl;
        for (auto& t : p.threads)
        {
            std::wcout << L"    Thread ID: " << t.threadID << std::endl;
        }

        std::wcout << L"StartUp Registry Programs:" << std::endl;
        ScanStartupKeys();
            
    }

    return 0;
}
