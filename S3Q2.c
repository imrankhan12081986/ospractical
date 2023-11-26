#include<stdio.h>

struct  Process{
    int ID, arrivalTime, burstTime, completionTime, turnaroundTime, waitingTime;
};

void sort(struct Process p[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[j].arrivalTime > p[j+1].arrivalTime){
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void displayGanttChart(struct Process p[], int n){
    printf("\n\nGantt Chart : \n");
    for(int i=0;i<n;i++){
        printf("| %d ", p[i].ID); 
    }
    printf("|\n0");
    for(int i=0;i<n;i++){
        printf("   %d",p[i].completionTime);
    }
    printf("\n\nProcess\tArrival_Time\tCPU_Burst\tTurnaroundTime\tWaitTime");
    for(int i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].ID, p[i].arrivalTime, p[i].burstTime,p[i].turnaroundTime,p[i].waitingTime);
    }
}

void FCFS(struct Process p[], int n){
    sort(p, n);
    int ioWaitingTime = 2, totalTurnaroundTime = 0, totalWaitingTime = 0;
    for(int i=0;i<n;i++){
        if(i==0){
            p[i].completionTime = p[i].burstTime + ioWaitingTime;
        }
        else{
            p[i].completionTime = p[i-1].completionTime + p[i].burstTime + ioWaitingTime;
        }

        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;

        totalTurnaroundTime += p[i].turnaroundTime;
        totalWaitingTime += p[i].waitingTime;
    }
    displayGanttChart(p, n);

    float avgTurnAround = (float)totalTurnaroundTime / (float)n; 
    float avgWaiting = (float)totalWaitingTime / (float)n; 
    printf("\nAverage turnaround : %f",avgTurnAround);
    printf("\nAverage wait time : %f",avgWaiting);
    
}

int main(){
    int n = 3;
    struct Process p[n];
    for(int i=0;i<n;i++){
        p[i].ID = i+1;
        printf("Enter Arival and Burst Time of Process P%d : ", i+1);
        scanf("%d%d",&p[i].arrivalTime, &p[i].burstTime);
    }
    FCFS(p, n);
}