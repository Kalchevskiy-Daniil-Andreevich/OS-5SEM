#include <iostream>

using namespace std;

int main()
{
	const int page_size = 4096;
	const int count_pages = 256;

	int total_pages_size = page_size * count_pages;

	int* memory = new int[total_pages_size / sizeof(int)];

	for (int i = 0; i < total_pages_size / sizeof(int); i++)
	{
		memory[i] = i;
	}

	int* memory_second = memory + 202 * page_size / sizeof(int) + 3598;

	cout << memory_second << endl;
	cout << *memory_second << endl;

	delete[] memory;

	return 0;

	// 202 - К  224 - а  235 - л  3598
	//e0e
}