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
int main()
{
    auto processes = getProcessList();
    for (const auto& p : processes)
    {
        std::wcout << L"PID:" << p.pid << " ";
        std::wcout << L"Parent ID:" << p.parentPid << " ";
        std::wcout << L"Name:" << p.name << " ";
        std::wcout << L"Memory:" << p.memoryUsage <<std::endl;
            
    }

    return 0;
}
