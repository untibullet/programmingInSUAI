
#include <iostream>
#include<stdlib.h>

using namespace std;

const int SIZE = 4;

int (*(createRandomDoubleArray)())[SIZE] {
    static int outputArray[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            outputArray[i][j] = rand();
        }
    }

    return outputArray;
}

void printDoubleArray(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << "\t";
        }

        cout << endl;
    }
}

int* findMinInDoubleArray(int(*arr)[SIZE], int startIndex, int endIndex) {
    int minValue = arr[startIndex][startIndex];
    int lineOfMinValue = startIndex;
    int columnOfMinValue = startIndex;

    for (int i = startIndex + 1; i < endIndex + 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (minValue > arr[i][j]) {
                minValue = arr[i][j];
                lineOfMinValue = i;
                columnOfMinValue = j;
            }
        }
    }

    int outputArray[] = {minValue, lineOfMinValue, columnOfMinValue};

    return outputArray;
}

int main()
{
    int (*mainArray)[SIZE];

    mainArray = createRandomDoubleArray();

    printDoubleArray(mainArray);

    int minIntegerInFirstHalf = mainArray[0][0];
    int indexForFirstHalf[2];

    int minIntegerInSecondHalf = mainArray[(int) SIZE / 2 - 1][(int) SIZE / 2 - 1];
    int indexForSecondHalf[2];

    int* container; 

    container = findMinInDoubleArray(mainArray, 0, (int) SIZE / 2 - 1);
    minIntegerInFirstHalf = container[0];
    indexForFirstHalf[0] = container[1];
    indexForFirstHalf[1] = container[2];

    container = findMinInDoubleArray(mainArray, (int)SIZE / 2, SIZE - 1);
    minIntegerInSecondHalf = container[0];
    indexForSecondHalf[0] = container[1];
    indexForSecondHalf[1] = container[2];

    mainArray[indexForFirstHalf[0]][indexForFirstHalf[1]] = 
        minIntegerInSecondHalf;

    mainArray[indexForSecondHalf[0]][indexForSecondHalf[1]] =
        minIntegerInFirstHalf;

    cout << "Minimum in first half: " << minIntegerInFirstHalf << endl;
    cout << "Minimum in second half: " << minIntegerInSecondHalf << endl;

    printDoubleArray(mainArray);

    return 0;
}