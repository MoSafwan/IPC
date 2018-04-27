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
    
    int arr1[2][2] = { {1,2}, {3,4} };
    int arr2[2][2] = { {5,6}, {7,8} };
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);

    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    shm = (int*) shmat(shmid, NULL, 0);
    
    if (shm == (int *) -1 ){
        perror("shmat");
        exit(1);
    }
    
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            *shm = 0;
            for (int k=0; k<2; k++){
                *shm += arr1[i][k]*arr2[k][j];
            }
            shm += sizeof(int);
        }
    }
    
    //sleep(2);
    
    shmdt(shm);
 
    return 0;
}