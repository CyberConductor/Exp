#pragma once
#include <windows.h>
#include <string>

void CheckStartupRegistry(HKEY rootKey, const std::wstring& subKey);
void ScanStartupKeys();
