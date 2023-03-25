
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int* createExpandedArray(int arr[], int size, int insertIndex, int insertNumber) {
    int *output = new int[size + 1];
    int delta = 0;

    for (int i = 0; i < size + 1; i++) {
        if (i == insertIndex + 1) {
            output[i] = insertNumber;
            delta = 1;
        }
        else {
            output[i] = arr[i - delta];
        }
    }

    return output;
}

int* createRandomArray(int size) {
    int* output = new int[size];

    for (int i = 0; i < size; i++) {
        output[i] = rand() * pow(-1, rand() % 2);
    }

    return output;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int insertNumber;
    cout << "Enter a number: ";
    cin >> insertNumber;

    int* arr = createRandomArray(size); //change this array

    int maxNegativeNumber;
    int indexOfMaxNegativeNumber;
    bool negativeNumberIsInclude = false;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            maxNegativeNumber = arr[i];
            indexOfMaxNegativeNumber = i;
            negativeNumberIsInclude = true;
            break;
        }
    }

    if (!negativeNumberIsInclude) {
        cout << "Error" << endl;
        return 0;
    }

    for (int i = indexOfMaxNegativeNumber + 1; i < size; i++) {
        if (arr[i] < 0 && maxNegativeNumber < arr[i]) {
            maxNegativeNumber = arr[i];
            indexOfMaxNegativeNumber = i;
        }
    }

    int* expArr = createExpandedArray(arr, size, indexOfMaxNegativeNumber, insertNumber);

    delete [] arr;

    for (int i = 0; i < size + 1; i++) {
        cout << expArr[i] << " ";
    }

    return 0;
}