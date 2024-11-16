
#include <stdio.h>
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[] = {3,9,6,5,2,8,42,36,26};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
        target = 10;
        result = binarySearch(arr, size, target);
        if (result != -1) {
            printf("Element %d found at index %d.\n", target, result);
        } else {
            printf("Element %d not found in the array.\n", target);
        }

    }
    return 0;
}
