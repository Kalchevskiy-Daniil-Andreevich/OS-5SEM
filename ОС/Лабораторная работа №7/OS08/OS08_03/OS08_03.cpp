#include <iostream>
#include <windows.h>
#include <ctime>
#define SECOND 10000000

using namespace std;

HANDLE startTimer = NULL;
long long tStartTimer = -3 * SECOND;
HANDLE endTimer = NULL;
long long tEndTimer = -15 * SECOND;

int counter = 0;

DWORD WINAPI ChildThread()
{
	while (true)
	{
		WaitForSingleObject(startTimer, INFINITE);
		cout << clock() << " - startTimer activated!" << endl;
		cout << "Iterations count: " << counter << endl;
	}
}	

int main()
{
	startTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	cout << clock() << " - started!" << endl;
	if (!SetWaitableTimer(startTimer, (LARGE_INTEGER*)&tStartTimer, 3000, NULL, NULL, FALSE))
		throw "ERROR SetWaitableTimer";

	DWORD childId = 0;
	HANDLE nChild = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildThread, NULL, NULL, &childId);

	endTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	if (!SetWaitableTimer(endTimer, (LARGE_INTEGER*)&tEndTimer, 0, NULL, NULL, FALSE))
		throw "ERROR SetWaitableTimer";

	while (true)
	{
		if (WaitForSingleObject(endTimer, 0) == WAIT_OBJECT_0)
		{
			cout << clock() << " - endTimer activated!" << endl;
			Sleep(50);
			cout << "Terminated!" << endl;
			TerminateThread(nChild, 0);
			break;
		}
		counter++;
	}

	cout << "Iterations count: " << counter << endl;

	system("pause");
	return 0;
}