#pragma once
#include "ProcessInfo.h"
#include <vector>
#include <TlHelp32.h>
#include <Psapi.h>
std::vector<ProcessInfo> getProcessList();