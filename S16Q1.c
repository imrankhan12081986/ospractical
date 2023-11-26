#include<stdio.h>
#include<time.h>

int main(){
    clock_t start, end;
    double executionTime;

    start = clock();
    for(int i=0;i<1000000000;i++){}
    end = clock();
    executionTime = ((double) (end-start)) / CLOCKS_PER_SEC;
    printf("Execution Time : %f", executionTime);
}