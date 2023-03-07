#include <iostream>
#include <math.h>

using namespace std;

void task1(){
    long int number;
    
    scanf("%ld", &number);
    
    int n = 0;
    int remain;
    while (number > 0){
        remain = number % 10;
        if (remain == 7){
            n++;
        }
        number /= 10;
    }
    
    printf(">> %d\n", n);
}

void task2(){
    int number;
    
    scanf("%d", &number);
    
    switch (number){
        case  1:
            printf("Winter\n");
            break;
        case 2:
            printf("Spring\n");
            break;
        case 3:
            printf("Summer\n");
            break;
        case 4:
            printf("Autumn\n");
            break;
        default:
            printf("Nothing\n");
            break;
    }
}

void task3(){
    long int number;
    
    scanf("%ld", &number);
    
    int output = 0;
    int n = 0;
    int remain;
    while (number > 0){
        remain = number % 10;
        output += remain * (int) pow(2, n);
        n++;
        number /= 10;
    }
    
    printf(">> %d\n", output);
}

int main(){
    task1();
    
    task2();
    
    task3();
    
    return 0;
}
