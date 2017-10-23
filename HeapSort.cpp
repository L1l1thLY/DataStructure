#include <iostream>

int HeapAdjust (int * arrayToSort, int i, int nLength) {
    int nChild, nTemp;
    for( ; (2 * i + 1) < nLength; i = nChild) {
        nChild = 2 * i + 1;
        if (nChild < nLength - 1 && arrayToSort[nChild +1] > arrayToSort[nChild]) {
           ++nChild; 
        }
        if (arrayToSort[i] < arrayToSort[nChild]) {
            nTemp = arrayToSort[i];
            arrayToSort[i] = arrayToSort[nChild];
            arrayToSort[nChild] = nTemp;
        } else break;
    }
    return 0;
}

int HeapSort (int * arrayToSort, int length) {
    int i;
    for (i = length / 2 - 1; i>= 0; --i) {
        HeapAdjust (arrayToSort, i, length);
    }
    for (i = length - 1; i > 0; --i) {
        arrayToSort[i] = arrayToSort[0] ^ arrayToSort[i];
        arrayToSort[0] = arrayToSort[0] ^ arrayToSort[i];
        arrayToSort[i] = arrayToSort[0] ^ arrayToSort[i];
        HeapAdjust (arrayToSort, 0, i);
    }
    return 0;
}
int main (void) {

    int array[10] = {13,78,12,22,34,1,23,5,7,99};

    HeapSort (array, 10);

    for (int i = 0; i < 10; i++) 
        std::cout << array[i] << std::endl; 

    return 0;
}

