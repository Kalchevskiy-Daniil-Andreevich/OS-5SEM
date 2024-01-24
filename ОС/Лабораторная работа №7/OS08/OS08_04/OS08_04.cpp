#include <iostream>
#include <windows.h>
#include <ctime>

#define SECOND 10000000 

using namespace std;

HANDLE timer;

int main()
{
	clock_t start = clock();
	DWORD pid = GetCurrentProcessId();
	cout << "PID: " << pid << endl;
	
	long long tTimer = -60 * SECOND;

	timer = CreateWaitableTimer(NULL, FALSE, L"OS08_04");

	if (!SetWaitableTimer(timer, (LARGE_INTEGER*)&tTimer, 60000, NULL, NULL, FALSE))
		cout << "ERROR SetWaitableTimer";

	LPCWSTR path = L"D:\\ОС\\Лабораторная работа №7\\OS08\\x64\\Debug\\OS08_04_X.exe";

	PROCESS_INFORMATION pi1;
	PROCESS_INFORMATION pi2;

	pi1.dwThreadId = 1, pi2.dwThreadId = 2;
	{
		STARTUPINFO si1;
		ZeroMemory(&si1, sizeof(STARTUPINFO));
		si1.cb = sizeof(STARTUPINFO);
		if (CreateProcess(path, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
			cout << "Process 1 was created!" << endl;
		else
			cout << "Process 1 wasn't created!" << endl;
	}
	{
		STARTUPINFO si2;
		ZeroMemory(&si2, sizeof(STARTUPINFO));
		si2.cb = sizeof(STARTUPINFO);
		if (CreateProcess(path, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
			cout << "Process 2 was created!" << endl;
		else
			cout << "Process 2 wasn't created!" << endl;
	}

	WaitForSingleObject(pi1.hProcess, INFINITE);
	WaitForSingleObject(pi2.hProcess, INFINITE);
	CloseHandle(timer);

	cout << "Elapsed time: " << clock() - start << endl;
	system("pause");
	return 0;
}