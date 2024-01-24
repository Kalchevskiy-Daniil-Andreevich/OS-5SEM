#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	time_t nowTime = time(NULL);
	struct tm now;
	char buffer[20];
	localtime_s(&now, &nowTime);
	strftime(buffer, sizeof(buffer), "%d.%m.%y %H:%M:%S", &now);

	cout << buffer;

	return 0;
}