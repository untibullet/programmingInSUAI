#include <iostream>
#include <math.h>
#include "lab9.h"

using namespace std;

void print(int* arg) {
    cout << "len: " << arg[0] << " ";
    for (int i = arg[0]; i > 0; i--) {
        cout << arg[i] << "*x^" << i - 1 << " ";
    }

    cout << endl;
}

void task()
{
    int* firstPol = getPolynomial(1);

    int* secondPol = getPolynomial(2);

    const int d1 = firstPol[0];
    const int d2 = secondPol[0];

    int* quotient =  new int[d1 + 1];
    quotient[0] = d1;
    setDefaultValue(quotient, 0);

    int* tmp = new int[d1 + 1];
    tmp[0] = d1;
    setDefaultValue(tmp, 0);

    int shift;
    int coef;
    for (int i = d1; i >= d2; i--) {
        if (firstPol[i] == 0) {
            continue;
        }

        shift = i - d2;
        coef = firstPol[i];
        quotient[shift + 1] = coef;

        tmp = multPolynomial(secondPol, coef, shift);

        subPolynomials(firstPol, tmp);
    }

    cout << "finaly:" << endl;
    cout << "remainder >> ";
    print(firstPol);
    cout << "quo >>";
    print(quotient);

    delete[] firstPol;
    delete[] secondPol;
    delete[] quotient;
    delete[] tmp;
}

int* getPolynomial(int number) {
    int len;
    cout << "Enter the senior degree (size) of polynomial" << number << ":" << endl;
    cin >> len;

    len++;  // if len == 6 => x^5, but we want to x^6 

    int* polynomial = new int[len + 1];  // the first element wiil be <len>
    polynomial[0] = len;

    cout << "Enter the coefficients (must be integer):" << endl;
    for (int i = 1; i < len + 1; i++) {
        cout << "Enter coef. for x^" << i - 1 << ": ";
        cin >> polynomial[i];
        cout << endl;
    }

    return polynomial;
}

int* multPolynomial(int* p, int coef, int shift) {
    int* output = new int[p[0] + shift + 1];
    output[0] = p[0] + shift;
    setDefaultValue(output, 0);

    for (int i = p[0]; i > 0; i--) {
        output[i + shift] = p[i] * coef;
    }

    return output;
}

void subPolynomials(int* p1, int* p2) {
    for (int i = p2[0]; i > 0; i--) {
        p1[i] = p1[i] - p2[i];
    }
}

void setDefaultValue(int* pol, int value) {
    for (int i = pol[0]; i > 0; i--) {
        pol[i] = value;
    }
}