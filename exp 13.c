#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n, arr[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        if (choice >= 1 && choice <= 3) {
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            printf("Enter %d elements:\n", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }

            switch (choice) {
                case 1:
                    printf("Performing Selection Sort...\n");
                    selectionSort(arr, n);
                    break;
                case 2:
                    printf("Performing Bubble Sort...\n");
                    bubbleSort(arr, n);
                    break;
                case 3:
                    printf("Performing Insertion Sort...\n");
                    insertionSort(arr, n);
                    break;
            }

            printf("Sorted Array: ");
            displayArray(arr, n);
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
