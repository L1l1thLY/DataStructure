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

int selectMinKeyPosition (int* numList, int startPoint, int sizeOfList) {
    int minKeyPosition = startPoint;
    for (int i = startPoint + 1; i < sizeOfList; ++i) {
        if (numList[i] < numList[minKeyPosition])
            minKeyPosition = i;
    }
   
    return minKeyPosition;
}

void simpleSelectionSort (int* arrayToSort, int count) {
    for (int i = 0; i < count; ++i) {
        int minKeyPosition = selectMinKeyPosition (arrayToSort, i, count);
        if (i != minKeyPosition)
            swapInt(&arrayToSort[i], &arrayToSort[minKeyPosition]);
    }
}
int main (void) {

    int array[10] = {34,-12,23,45,21,77,12,56,89,1};
    //
    simpleSelectionSort (array, 10);
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}
