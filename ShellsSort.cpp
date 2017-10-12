#include <iostream>

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

void shellInsert (int* arrayToSort, int increment, int count) {
    for (int i = increment; i < count; i++) {
        if (arrayToSort[i] < arrayToSort[i - increment]) {
            int j = i - increment;
            int temp = arrayToSort[i];
            for ( ; j >= 0 && arrayToSort[j] > temp; j -= increment) {
                arrayToSort[j + increment] = arrayToSort[j];
            }
            arrayToSort[j + increment] = temp;
        }
    }
}

void shellSort (int* arrayToSort, int* incrementQueue, int t, int lengthOfArray) {
    for (int i = 0; i < t; ++i) {
        shellInsert (arrayToSort, incrementQueue[i], lengthOfArray);
    }
}

int main (void) {

    int array[10] = {34,-12,23,45,21,77,12,56,89,1};
    int incrementQueue[1] = {1};

    shellSort (array, incrementQueue, 1, 10);
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}
