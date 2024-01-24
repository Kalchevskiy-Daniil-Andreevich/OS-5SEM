#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	for (int i = 0; i < 100000; i++)
	{
		DWORD pid = GetCurrentProcessId();
		cout << "PID: " << pid << endl;
		Sleep(1000);
	}
}