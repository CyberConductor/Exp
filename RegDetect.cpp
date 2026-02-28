#include "RegDetect.h"
#include <iostream>
#include <winreg.h>

void CheckStartupRegistry(HKEY rootKey, const std::wstring& subKey)
{
	HKEY hKey;
	if (RegOpenKeyExW(rootKey, subKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS)
	{
		std::wcout << "Failed to open key" << std::endl;
		return;
	}
	DWORD index = 0;
	wchar_t valueName[256];
	BYTE data[1024];
	DWORD valueNameSize;
	DWORD dataSize;
	DWORD type;
	
	while (true)
	{
		valueNameSize = 256;
		dataSize = 1024;

		LONG ret = RegEnumValueW(hKey, index, valueName, &valueNameSize, nullptr, &type, data, &dataSize);
		if (ret == ERROR_SUCCESS && type == REG_SZ)
		{
			std::wstring programPath((wchar_t*)data, dataSize / sizeof(wchar_t) - 1);
			std::wcout << L"Startup value: " << valueName << L"->" << programPath << std::endl;
			if (programPath.find(L"AppData") != std::wstring::npos || programPath.find(L"Temp") != std::wstring::npos)
			{
				std::wcout << programPath << " is suspicous!" << std::endl;
			}
		}

		index++;

	}
	RegCloseKey(hKey);

}

void ScanStartupKeys()
{
	CheckStartupRegistry(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run");
}



