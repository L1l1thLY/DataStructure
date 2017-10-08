#include <iostream>

int insertionSortFromBook(int * arrayToSort, int length) {
    int temp = 0;
    for (int i = 2; i < length; ++i) {
        if (arrayToSort[i] < arrayToSort[i-1]) {
            temp = arrayToSort[i];
            arrayToSort[i] = arrayToSort[i-1];
            int j;
            for (j = (i - 2); temp < arrayToSort[j]; j--) {
                arrayToSort[j+1] = arrayToSort [j];
            }
            arrayToSort[j+1] = temp;
        }
    }
    return 0;
}

int insertionSort(int* arrayToSort, int length) {
    int temp = 0;
    for (int i = 1; i < length; ++i) {
        if (arrayToSort[i] < arrayToSort[i-1]) {
            temp = arrayToSort[i];
            int j = i - 1;
            for (; temp < arrayToSort[j]; --j) {
                arrayToSort[j+1] = arrayToSort[j];
            }
            arrayToSort[j+1] = temp;
        }
    }
    return 0;
}

int main (void) {

    int array[10] = {13,78,12,22,34,1,23,5,7,99};

    insertionSort(array, 10);

    for (int i = 0; i < 10; i++) 
        std::cout << array[i] << std::endl; 

    return 0;
}
