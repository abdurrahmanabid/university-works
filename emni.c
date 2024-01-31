#include <stdio.h>

void bubbleSort(int array[], int index[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j+1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                // Swap index[j] and index[j+1] accordingly
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }
}

void printArrayWithIndex(int array[], int index[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Element %d: %d (Index: %d)\n", i + 1, array[i], index[i]);
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);

    int index[size];
    int i;
    for (i = 0; i < size; i++) {
        index[i] = i;
    }

    printf("Array before sorting:\n");
    printArrayWithIndex(array, index, size);

    bubbleSort(array, index, size);

    printf("Array after sorting:\n");
    printArrayWithIndex(array, index, size);

    return 0;
}
