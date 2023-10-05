#include <iostream>

int findLeftNegIndex(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            return i;
        }
    }
    return -1;
}

int findRightNegIndex(int arr[], int size) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] < 0) {
            return i;
        }
    }
    return -1;
}

void sortBetweenIndices(int arr[], int leftIndex, int rightIndex) {
    for (int i = leftIndex + 1; i < rightIndex; ++i) {
        for (int j = i + 1; j < rightIndex; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    const int arraySize = 10;
    int arr[arraySize] = { -10, 5, 7, -15, 8, -3, 12, -17, 4, -9 };

    int leftNegIndex = findLeftNegIndex(arr, arraySize);
    int rightNegIndex = findRightNegIndex(arr, arraySize);

    if (leftNegIndex != -1 && rightNegIndex != -1) {
        sortBetweenIndices(arr, leftNegIndex, rightNegIndex);

        for (int i = 0; i < arraySize; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "В массиве нет отрицательных элементов." << std::endl;
    }

    return 0;
}
