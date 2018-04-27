#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define SHSIZE 100

int main(){
    
    int shmid;
    key_t key;
    int* shm;
    int* s;
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, 0666);

    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    shm = (int*) shmat(shmid, NULL, 0);
    
    for(int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            printf("%d\t", *shm);
            shm += sizeof(int);
        }
        printf("\n");
    }
    
    shmdt(shm);
    
    return 0;
}
