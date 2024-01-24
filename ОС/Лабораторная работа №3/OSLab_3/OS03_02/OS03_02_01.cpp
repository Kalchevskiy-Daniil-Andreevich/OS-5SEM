#include <iostream>
#include <windows.h>

using namespace std;

int OS03_02_1()
{
	for (int i = 0; i < 50; i++)
	{
		DWORD pid = GetCurrentProcessId();
		cout << pid;
		Sleep(1000);
	}

	return 0;
}