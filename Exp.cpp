/*

Process Enumerator + Basic Behaviour Monitor

Goal :
Enumerate all running processes
Show PID
Show Parent PID
Show executable name
Show memory usage
Refresh every few seconds and detect new processes

*/

#include <iostream>
#include "ProcessOptions.h"
#include "ProcessInfo.h"
#include "ThreadInfo.h"

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
            
    }

    return 0;
}
