#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

bool stop = false;

int IsSimple(int number)
{
	for (int i = 2; i < number / 2; i++)
	{
		if ((number % i) == 0)
		{
			return 0;
		}
	}
	return 1;
}

DWORD ChildThread()
{
	DWORD tid = GetCurrentThreadId();
	for (long long i = 2;; i++)
	{
		if (stop)
			break;
		if (IsSimple(i))
			cout << i << endl;
	}
	return 0;
}

int main()
{
	clock_t start = clock();
	HANDLE timerHandle = OpenWaitableTimer(TIMER_ALL_ACCESS, FALSE, L"OS08_04");
	DWORD childId = NULL;

	HANDLE childHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildThread, NULL, 0, &childId);

	WaitForSingleObject(timerHandle, INFINITE);
	stop = true;
	WaitForSingleObject(timerHandle, INFINITE);
	CloseHandle(childHandle);

	cout << "Elapsed time: " << clock() - start << endl;
	system("pause");
	return 0;
}