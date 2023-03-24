
#include <iostream>

using namespace std;

int* createExpandedArray(int arr[], int indexOfMaxNegativeNumber, int insertNumber) {
    static int output[sizeof(arr) + 1];
    int delta = 0;

    for (int i = 0; i < sizeof(arr) + 1; i++) {
        if (i == indexOfMaxNegativeNumber + 1) {
            output[i] = insertNumber;
            delta = 1;
        }
        else {
            output[i] = arr[i - delta];
        }
    }

    return output;
}

int main()
{
    int insertNumber;
    cin >> insertNumber;

    int arr[] = {-100, 2, 52, 662, -14, -56, 0, 3}; //change this array

    int maxNegativeNumber;
    int indexOfMaxNegativeNumber;
    bool negativeNumberIsInclude = false;

    for (int i = 0; i < sizeof(arr); i++) {
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

    for (int i = indexOfMaxNegativeNumber + 1; i < sizeof(arr); i++) {
        if (arr[i] < 0 && maxNegativeNumber < arr[i]) {
            maxNegativeNumber = arr[i];
            indexOfMaxNegativeNumber = i;
        }
    }

    int* expArr = createExpandedArray(arr, indexOfMaxNegativeNumber, insertNumber);

    for (int i = 0; i < sizeof(expArr) + 1; i++) {
        cout << expArr[i] << " ";
    }

    return 0;
}