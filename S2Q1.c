#include<stdio.h>
#include<unistd.h>

int main(){
    int pid = fork();
    if(pid == -1){  
        printf("Fork Failed..!!");
        exit(0);
    }
    if(pid == 0){
        printf("\n\nChild Process ID : %d, Hello World..!!\n",getpid());
    }
    else{
        printf("Parent Process ID : %d, hii...", getpid());
    }
}