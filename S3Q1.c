#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
    } 
    
    else if (pid == 0) {
        printf("Child ID : %d\n",getpid());
        execl("/bin/ls", "ls", NULL);
    } 
    
    else {
      printf("Parent process going in sleep state...\n");
      sleep(2);
      printf("Parent process awake from sleep...");
    }
}
