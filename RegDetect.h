#pragma once
#include <windows.h>
#include <string>

void CheckStartupRegistry(HKEY rootkey, const std::wstring& subKey);
void ScanStartupKeys();
