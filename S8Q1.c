#include<stdio.h>

int main(){
    int process, resources;
    printf("Enter the number of processes : "); scanf("%d",&process);
    printf("Enter the number of resources : "); scanf("%d",&resources);

    int Max[process][resources], Allocation[process][resources], Need[process][resources];

    printf("\nEnter content of Max Matrix: \n");
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            scanf("%d", &Max[i][j]);
        }
    }

    printf("\nEnter content of Allocation Matrix: \n");
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\nContent of Need Matrix : \n");
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            Need[i][j] = Max[i][j] - Allocation[i][j];
            printf("%d\t", Need[i][j]);
        }
        printf("\n");
    }
}