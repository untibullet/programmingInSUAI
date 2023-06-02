#include <iostream>
#include <string>
#include <fstream>
#include "lab10.h"

using namespace std;

void task()
{
    string filename;
    cout << "Enter a file name:" << endl;
    cin >> filename;

    ifstream readFile;
    readFile.open(filename);

    ofstream writeFile;
    writeFile.open("result.txt");

    bool* inMultilineComment = new bool[1];
    inMultilineComment[0] = false;

    string line;
    while (getline(readFile, line)) {
        line = createCleanLine(line, inMultilineComment);

        writeFile << line << endl;
    }

    readFile.close();
    writeFile.close();

    cout << "File has been written" << endl;
}

string createCleanLine(string line, bool* inMultilineComment) {
    string cleanLine = "";

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '*' and line[i + 1] == '/') {
            inMultilineComment[0] = false;
            i++;
            continue;
        }

        if (inMultilineComment[0]) {
            continue;
        }

        if (line[i] == '/') {
            if (line[i + 1] == '/') {
                return cleanLine;
            }
            else if (line[i + 1] == '*') {
                inMultilineComment[0] = true;
                return cleanLine;
            }
        }


        cleanLine += line[i];
    }

    return cleanLine;
}
