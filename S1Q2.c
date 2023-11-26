#include<stdio.h>

int keyInMemory(int key, int frames, int memory[]){
    for(int i=0;i<frames;i++){
        if(key == memory[i]){
            return 1;
        }
    }
    return 0;
}

int FIFO(int frames, int refString[], int size){
    int memory[frames], pageFaults=0, frameIndex = 0, currentFrameIndex = 0;
    for(int i=0;i<frames;i++){
        memory[i] = -1;
    }

    for(int i=0;i<size;i++){
        if(!keyInMemory(refString[i], frames, memory)){
            pageFaults++;
            if(frameIndex<frames){
                memory[frameIndex] = refString[i];
                frameIndex++;
            }
            else{
                memory[currentFrameIndex] = refString[i];
                currentFrameIndex++;
                if(currentFrameIndex == frames){
                    currentFrameIndex = 0;
                }
            }
        }
        printf("\n%d : \t", refString[i]);
        for(int i=0;i<frames;i++){
            if(memory[i]!=-1){
                printf("%d\t", memory[i]);
            }
        }
    }
    return pageFaults;
}

int main(){
    int n=3;
    int refString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int pageFaults = FIFO(n, refString, sizeof(refString)/sizeof(refString[0]));
    printf("\n\nPage Faults : %d",pageFaults);
}