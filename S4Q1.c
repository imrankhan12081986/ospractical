#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int child_pid = fork();

    if (child_pid < 0) {
        printf("Fork failed");
        exit(1);
    }

    else if (child_pid == 0){
        printf("Child process with PID: %d\n", getpid());
        printf("Parent PID from the child process: %d\n", getppid());
        sleep(10);
        printf("Child process completed\n");
    } 

    else {
        printf("Parent process with PID: %d\n", getpid());
        printf("Child process created with PID: %d\n", child_pid);
        printf("Parent process is sleeping for 5 seconds\n");
        sleep(5);
        printf("Parent process completed\n");
    }
}
