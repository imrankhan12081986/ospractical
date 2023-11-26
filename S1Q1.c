 #include <stdio.h>
#include <unistd.h>

int main() {
    int pid, retnice;
    pid = fork();
    for (;;) {
        if (pid == 0) {
            retnice = nice(-5);
            printf("Child gets higher CPU priority %d \n", retnice);
            sleep(2);
        } 
        else if (pid > 0) {
            retnice = nice(4);
            printf("Parent gets lower CPU priority %d \n", retnice);
            sleep(2);
        } 
    }
}
