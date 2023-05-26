#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

bool isStringLengthEven(string somestr) {
    return somestr.length() % 2 == 0;
}

int increaseForOneOrZero(string somestr) {
    if (isStringLengthEven(somestr)) {
        return 1;
    }

    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;

    getline(cin, input);

    int start = 0;
    int count = 0;
    for (int end = 0; end < input.length(); end++) {
        if (input[end] == ' ') {
            count += increaseForOneOrZero(input.substr(start, end - start));
            start = end + 1;
        }
        else if (end == input.length() - 1) {
            count += increaseForOneOrZero(input.substr(start, end - start + 1));
        }
    }

    cout << count << endl;
}