#include<stdio.h>

int keyInMemory(int key, int memory[], int frames){
    for(int i=0;i<frames;i++){
        if(key == memory[i]){
            return 1;
        }
    }
    return 0;
}

int LRU(int referenceString[], int size, int frames){
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
                int leastRecent = size, victimFrame = 0;
                for(int j=0;j<frames;j++){
                    for(int k=i-1;k>=0;k--){
                        if(memory[j] == referenceString[k]){
                            if(k < leastRecent){
                                leastRecent = k;
                                victimFrame = j;
                            }
                            break;
                        }
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
    int frames, referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int size = sizeof(referenceString) / sizeof(referenceString[0]);
    printf("Enter the number of frames : ");
    scanf("%d",&frames);
    int pageFaults = LRU(referenceString, size, frames);
    printf("\nPage Faults : %d", pageFaults);
}