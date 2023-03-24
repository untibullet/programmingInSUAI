﻿
#include <iostream>
#include <math.h>
#include <clocale>

using namespace std;

int main()
{
    setlocale(0, "");

    cout << "Введите кол-во копеек:" << endl;
    int number;
    cin >> number;

    if (11 <= number % 100 && number % 100 <= 14) {
        printf("%d %s", number, "копеек");
        return 0;
    }

    int remainder = number % 10;

    if (remainder == 1) {
        printf("%d %s", number, "копейка");
        return 0;
    }

    switch (remainder) {
    case 0:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        printf("%d %s", number, "копеек");
        break;
    case 2:
    case 3:
    case 4:
        printf("%d %s", number, "копейки");
        break;
    }
}