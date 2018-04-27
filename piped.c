#include<stdio.h>
#include<unistd.h>

void multiply(int a[2][2], int b[2][2], int x[2][2]);
void print(int z[2][2]);

int main(void) {
	int pipefd1[2];
        int pipefd2[2];
	int pid;
	pipe(pipefd1);
        pipe(pipefd2);
	pid = fork();

	if(pid > 0) {
		fflush(stdin);
                int a[2][2] = {{1,2}, {3,4}};     
                int b[2][2] = {{5,6}, {7,8}};    
		printf("unamed_pipe [INFO] Parent Process\n");
		write(pipefd1[1],a,2*2*sizeof(int));
                write(pipefd2[1],b,2*2*sizeof(int));
	}
	else if(pid == 0) {
		sleep(5);
                int x[2][2];
                int y[2][2];
                int z[2][2];
		fflush(stdin);
		printf("unamed_pipe [INFO] Child Process\n");
		read(pipefd1[0], x, sizeof(x));
                read(pipefd2[0], y, sizeof(y));
                multiply(x, y, z);   // Function to Multiply
                print(z);   // Function to Print
		printf("\n");	
	}
	else {
		printf("unamed_pipe [ERROR] Error in creating child process\n");	
	}
	if(pid > 0) wait();
	return 0;
}

 void multiply(int a[2][2], int b[2][2], int x[2][2]){   
    int sum = 0;
    
    for (int c = 0; c < 2; c++) {
      for (int d = 0; d < 2; d++) {
        for (int k = 0; k < 2; k++) {
          sum = sum + a[c][k]*b[k][d];
        }
        x[c][d] = sum;
        sum = 0;
      }
    }
}


void print(int z[2][2]){
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                printf("%d\t", z[i][j]);
            }
            printf("\n");
        }
}
