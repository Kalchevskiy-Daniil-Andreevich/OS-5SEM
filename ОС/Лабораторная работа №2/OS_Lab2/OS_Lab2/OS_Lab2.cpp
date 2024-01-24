#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	for (int i = 0; i < 1000; i++)
	{
		DWORD pid = GetCurrentProcessId();
		cout << pid << "-" << i + 1 << endl;
		Sleep(2000);
	}
    return 0;
}