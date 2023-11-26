#include<stdio.h>
#define n 5
#define m 4

int Allocation[n][m], Max[n][m], Need[n][m], Available[m], safeSequence[n];

void init(){
    int available[] = {1,5,2,0};

    int alloc[][4] = {
        {0,0,1,2},
        {1,0,0,0},
        {1,3,5,4},
        {0,6,3,2},
        {0,0,1,4}
    };

    int max[][4] = {
        {0,0,1,2},
        {1,7,5,0},
        {2,3,5,6},
        {0,6,5,2},
        {0,6,5,6}
    };

    for(int i=0;i<m;i++){
        Available[i] = available[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Allocation[i][j] = alloc[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Max[i][j] = max[i][j];
        }
    }
}

void calcNeed(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

void displayNeed(){
    printf("Content of Need array : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d\t", Need[i][j]);
        }
        printf("\n");
    }
}

int isSafe(){
    int Work[m], Finish[n], count = 0;
    for(int i=0;i<n;i++){
        Finish[i] = 0;
    }
    for(int i=0;i<m ;i++){   
        Work[i] = Available[i];
    }   

    while(count < n){
        int found = 0;
        for(int i=0;i<n;i++){
            if(!Finish[i]){
                int j;
                for(j=0;j<m;j++){
                    if(Need[i][j] > Work[j]){
                        break;
                    }
                }
                if(j == m){
                    for(j=0;j<m;j++){
                        Work[j] += Allocation[i][j];
                    }
                    found = 1;
                    safeSequence[count++] = i;
                    Finish[i] = 1;
                }
            }
        }
        if(!found){
            return 0;
        }
    }
    return 1;
}

int requestGranted(int pid, int request[]){
    for(int i=0;i<m;i++){
        if(request[i] > Need[pid][i] || request[i] > Available[i]){
            return 0;
        }
    }

    for(int i=0;i<m;i++){
        Need[pid][i] -= request[i];
        Available[i] -= request[i];
        Allocation[pid][i] += request[i];
    }

    if(isSafe()){
        return 1;
    }
    else{
        for(int i=0;i<m;i++){
            Need[pid][i] += request[i];
            Available[i] += request[i];
            Allocation[pid][i] -= request[i];
        }
        return 0;
    }
}

int main(){
    init();
    calcNeed();
    displayNeed();
    if(isSafe()){
        printf("\nSafe Sequence : ");
        for(int i=0;i<n;i++){
            printf("%d\t", safeSequence[i]);
        }
    }
    else{
        printf("\nSystem is not in safe state..!!");
    }

    int pid = 1;
    int request[] = {0,4,2,0};
    if(requestGranted(1, request)){
        printf("\nRequest for {0,4,2,0} Granted..!!");
    }
    else{
        printf("\nCannot be Granted..!!");
    }
}