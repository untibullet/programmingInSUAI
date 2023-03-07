#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

void task1(){
    static int number;
    
    printf("Entry your number below:\n");
    scanf("%d", &number);
    
    if (number % 2 == 0){
        printf("Your number is even\n");
    }
    else {
        printf("Your number is uneven\n");
    }
}

int count(int number){
    int n = 0;
    
    while (number > 0){
        n += 1;
        number = number / 10;
    }
    
    return n;
}

void task2(){
    int number;
    
    printf("Entry your number:\n");
    scanf("%d", &number);
    
    int n = count(number);
    
    int integer;
    for (n; n > 0; n--){
        integer = number / (int) pow(10, n - 1);
        printf("%d ", integer);
        number = number % (int) pow(10, n - 1);
    }
}

int main()
{
    task1();
    
    task2();

    return 0;
}
