#include <stdio.h>

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Binary Search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1; // key not found
}

int main() {
    int arr[] = {9, 3, 17, 5, 11, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arrSize - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);

    int key = 11;
    int index = binarySearch(arr, 0, arrSize - 1, key);
    if (index != -1)
        printf("\n%d found at index %d\n", key, index);
    else
        printf("\n%d not found in the array\n", key);

    return 0;
}
