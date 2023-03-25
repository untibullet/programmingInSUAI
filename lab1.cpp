
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float A, B, C, D;

    cout << "Enter A, B, C, B:" << endl;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    float multiplier1, multiplier2, multiplier3;

    multiplier1 = 1 / pow(A, 2);
    multiplier2 = pow(D / 10, 3);
    multiplier3 = pow(C + D, 2);

    float output = multiplier1 * multiplier2 * multiplier3;
    
    cout << "using cout: " << output << endl;

    printf("using printf: %f\n", output);
    
    return 0;

}
