#include <iostream>
#include <Windows.h>

using namespace std;

void sh(HANDLE heap) 
{
    PROCESS_HEAP_ENTRY entry;
    entry.lpData = nullptr;

    SIZE_T totalSize = 0;
    SIZE_T totalCommittedSize = 0;
    SIZE_T totalUncommittedSize = 0;

    while (HeapWalk(heap, &entry))
    {
        totalSize += entry.cbData;
        if (entry.wFlags & PROCESS_HEAP_ENTRY_BUSY) 
        {
            totalCommittedSize += entry.cbData;
            cout << "-- address = " << hex << entry.lpData
                << ", size = " << dec << entry.cbData << " U" << "\n";
        }
        else 
        {
            totalUncommittedSize += entry.cbData;
            cout << "-- address = " << hex << entry.lpData
                << ", size = " << dec << entry.cbData << " B" << "\n";
        }
    }

    std::cout << "Размер heap: " << totalSize << " байт" << std::endl;
    std::cout << "Размер распределенных областей памяти: " << totalCommittedSize << " байт" << std::endl;
    std::cout << "Размер нераспределенных областей памяти: " << totalUncommittedSize << " байт" << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    HANDLE heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 4 * 1024 * 1024, 0);

    std::cout << "Информация до размещения массива:" << std::endl;
    sh(heap);

    const int arraySize = 300000;
    int* array = new int[arraySize];

    std::cout << "Информация после размещения массива:" << std::endl;
    sh(heap);

    delete[] array;

    return 0;
}