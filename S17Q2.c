#include<stdio.h>

int keyInMemory(int key, int memory[], int frames){
    for(int i=0;i<frames;i++){
        if(key == memory[i]){
            return 1;
        }
    }
    return 0;
}

int OPT(int referenceString[], int size, int frames){
    int memory[frames], pagaFaults = 0, currentIndex = 0;
    for(int i=0;i<frames;i++){
        memory[i] = -1;
    }
    
    for(int i=0;i<size;i++){
        if(!keyInMemory(referenceString[i], memory, frames)){
            pagaFaults++;
            if(currentIndex < frames){
                memory[currentIndex++] = referenceString[i];
            }
            else{
                int farthest = 0, victimFrame;
                for(int j=0;j<frames;j++){
                    int found = 0;
                    for(int k=i+1;k<size;k++){
                        if(memory[j] == referenceString[k]){
                            found = 1;
                            if(k > farthest){
                                farthest = k;
                                victimFrame = j;
                            }
                            break;
                        }
                    }
                    if(!found){
                        victimFrame = j;
                        break;
                    }
                }
                memory[victimFrame] = referenceString[i];
            }
        }
        
        printf("\n%d : \t", referenceString[i]);
        for(int i=0;i<frames;i++){
            if(memory[i] != -1){
                printf("%d\t", memory[i]);
            }
        }
    }
    return pagaFaults;
}

int main(){
    int frames, referenceString[] = {12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
    int size = sizeof(referenceString) / sizeof(referenceString[0]);
    printf("Enter the number of frames : ");
    scanf("%d",&frames);
    int pageFaults = OPT(referenceString, size, frames);
    printf("\nPage Faults : %d", pageFaults);
}