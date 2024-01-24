#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	clock_t time = clock();
	int counter = 0;
	bool flag = true;

	while (true)
	{
		counter++;
		clock_t time2 = clock();
		if (time2 - time == 5000 && flag)
		{
			cout << "Value after 5 seconds: " << counter << endl;
			flag = false;
		}
		if (time2 - time == 10000 && !flag)
		{
			cout << "Value after 10 seconds: " << counter << endl;
			flag = true;
		}
		if (time2 - time == 15000 && flag)
		{
			cout << "Result value: " << counter << endl;
			flag = false;
			break;
		}
	}

	return 0;
}