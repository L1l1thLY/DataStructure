#include <iostream>

int globalCounter = 0;
void swapInt (int* a, int* b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void newSwap (int *a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int bubbleSort (int* arrayToSort, int count) {
    for (int i = 0; i < count; ++i) {
        for (int k = 0; k < count - 1 - i; ++k) {
            if (arrayToSort[k] > arrayToSort[k+1]) {
                newSwap (&arrayToSort[k], &arrayToSort[k+1]);
            }
        }
    }
    return 0;
}

int qPartition (int* childList, int low, int high) {

    int pivotkey = childList[low];
    while  (low < high) {
        while (low < high && childList[high] >= pivotkey)
            --high;
        newSwap (&childList[low], &childList[high]);
        std::cout << "The result of swap is " << childList[high] << std::endl;
        while (low < high && childList[low] <= pivotkey)
            ++low;
        newSwap (&childList[low], &childList[high]);
    }
    globalCounter++;
    return low;
}
int quickSort (int* arrayToSort, int low, int high) {
    if (low < high) {
        int pivoloc = qPartition (arrayToSort, low, high);
        std::cout << globalCounter << " partition(s) done! pavoloc is " << pivoloc << std::endl;
        std::cout << "pivotkey is " << arrayToSort[pivoloc] << std::endl;
        quickSort (arrayToSort, low, pivoloc - 1);
        quickSort (arrayToSort, pivoloc + 1, high);
    }

    return 0;
}
int main (void) {

    int array[10] = {34,-12,23,45,21,77,12,56,89,1};
    quickSort (array, 0, 9);
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}
