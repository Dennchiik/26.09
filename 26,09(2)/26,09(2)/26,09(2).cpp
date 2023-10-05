#include <iostream>

const int arraySize = 20;
const int minValue = 1;
const int maxValue = 20;

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

void shuffleArray(int arr[], int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = getRandomNumber(0, i);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int findPosition(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void customSort(int arr[], int left, int right) {
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        arr[i] = minValue + i;
    }

    srand(time(NULL));
    shuffleArray(arr, arraySize);

    int randomValue = getRandomNumber(minValue, maxValue);
    int position = findPosition(arr, arraySize, randomValue);

    if (position != -1) {
        customSort(arr, 0, position - 1);
        customSort(arr, position + 1, arraySize - 1);
    }

    for (int i = 0; i < arraySize; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
