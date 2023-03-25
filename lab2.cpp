
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	cout << "Entry X:" << endl;

	float x;
	cin >> x;

	double output;
	if (x > 4.5) {
		output = 2 * x;
	}
	else if (x < 0) {
		output = exp(-1 * x);
	}
	else {
		output = 1 - log(fabs(1 - pow(x, 2)));
	}

	cout << output << endl;
	
	return 0;
}
