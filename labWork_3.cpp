#include <iostream>
#include <math.h>

using namespace std;

void task1(){
    float PI;
    
    long int n;
    
    printf("Enter the precision of calculation PI *integer*:\n>> ");
    scanf("%ld", &n);
    
    float sum;
    for (n; n > 0; n--){
        sum += ((float) 4 * pow(-1, n)) / ((float) 1 + 2 * n);
    }
    
    PI = 4 + sum;
    
    printf("%f\n", PI);
}

void task2(){
    int count;
    int integer;
    
    printf("Enter the count of numbers:\n>> ");
    scanf("%d", &count);
    
    printf("Enter the integer:\n>> ");
    scanf("%d", &integer);
    
    for (int i = 1; i <= count; i++){
        printf("%d ", integer * i);
    }
    
    printf("\n");
}

int main()
{
    task1();
    
    task2();

    return 0;
}
