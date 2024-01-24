#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		DWORD procId = GetCurrentProcessId();
		
		cout << "Current process id - " << procId << endl;
		Sleep(1000);
	}
}