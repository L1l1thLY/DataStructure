#include <iostream>

void swapInt (int* a, int* b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

int bubbleSort (int* arrayToSort, int count) {
    for (int i = 0; i < count; ++i) {
        for (int k = 0; k < count - 1 - i; ++k) {
            if (arrayToSort[k] > arrayToSort[k+1]) {
                swapInt (&arrayToSort[k], &arrayToSort[k+1]);
            }
        }
    }
    return 0;
}

int quickSort (int* arrayToSort, int count) {

}
int main (void) {

    int array[10] = {34,-12,23,45,21,77,12,56,89,1};
    bubbleSort (array, 10);
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}
