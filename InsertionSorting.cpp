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
            for (; (j >= 0) && temp < arrayToSort[j]; --j) {

                arrayToSort[j+1] = arrayToSort[j];
            }
            arrayToSort[j+1] = temp;
        }
    }
    return 0;
}

int binaryInsertionSort(int * arrayToSort, int length) {
    int temp = 0;
    for (int i = 1; i < length; ++i) {
        temp = arrayToSort[i];
        int low = 0, high = i-1;
        while (low <= high) {
            int m = (low + high) / 2;
            if (temp < arrayToSort[m])
                high = m - 1;
            else
                low = m + 1;
        }
        for (int j = (i - 1); j >= (high + 1); --j)
            arrayToSort[j+1] = arrayToSort[j];
        arrayToSort[high+1] = temp;

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
