#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("This is the child process with PID: %d\n", getpid());
        sleep(8);
        printf("Child process completed.\n");
    } 
    else { 
        printf("This is the parent process with PID: %d\n", getpid());
        sleep(4);
        printf("Parent process completed.\n");
    }
}
