#include <iostream>
#include "lab7.h"

using namespace std;

const int COUNT_OF_NUMBERS = 500000;
const int INTERVAL = 10000;

void task()
{
    int intervals[10] = {0};

    int index;
    long step = getRandom();
    for (int i = 0; i < COUNT_OF_NUMBERS; i++) {
        index = (int)(step / INTERVAL);
        intervals[index] += 1;
        step = getRandom(step);
    }

    for (int counts : intervals) {
        cout << counts << ' ' << (float) counts / COUNT_OF_NUMBERS << '%' << endl;
    }
}

long getRandom(int seed) {
    int state = seed;
    state = (state * 4231 + 12345) % 100000;

    return state;
}
