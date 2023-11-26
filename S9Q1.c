#include<stdio.h>
#include<unistd.h>

int main(){
    int pid = fork();
    if(pid == 0){
        printf("Chlld Process Executing..!!\n");
        execl("/bin/ls","ls",NULL);
    }
    else{
        printf("Parent Process going in sleep..!!\n");
        sleep(4);
        printf("Parent Process Completed..!!");
    }
}