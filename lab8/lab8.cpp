#include <iostream>
#include <math.h>
#include "lab8.h"

using namespace std;

int comp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void task()
{
    int mass[] { 2, 4, 1, 10, 10, 10, 41, 41, 19, 3, 42, 43};

    qsort(mass, size(mass), sizeof(mass[0]), comp);

    int number;
    cin >> number;

    int index = binarySearch(number, mass, 0, size(mass) - 1);

    cout << mass[index] << endl;
}

int binarySearch(int number, int mass[], int start, int end) {
    if (start == end) {
        return start;
    }

    int len = end - start;
    int median = (int)(len / 2) + start;

    if ((len + 1) % 2 == 0) {
        int* indexes = skipDuplicates(mass, start, end, median, median + 1);
        if (fabs(mass[indexes[0]] - number) < fabs(mass[indexes[1]] - number)) {
            end = median;
        }
        else {start = median + 1;}
    }
    else {
        if (fabs(mass[median - 1] - number) < fabs(mass[median + 1] - number)) {
            end = median;
        }
        else {start = median;}
    }
    
    return binarySearch(number, mass, start, end);
}

int* skipDuplicates(int* mass, int start, int end, int left, int right) {
    while (left != start and right != end and mass[left] == mass[right]) {
        if (left > start) {
            left--;
        }
        if (right < end) {
            right++;
        }
    }

    int* output = new int[2];
    output[0] = left;
    output[1] = right;

    return output;
}
