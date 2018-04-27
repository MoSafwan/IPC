#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


int main(void) {
	int fd, retval;
	int fd2, retval2;
	int buffer[2][2];
	int buffer2[2][2];	
	fd = open("/home/hamzastic_/Desktop/quiz/myfifo",O_RDONLY);
	fd2 = open("/home/hamzastic_/Desktop/quiz/myfifos",O_RDONLY);	
	retval = read(fd, buffer, sizeof(buffer));
	retval2 = read(fd2, buffer2, sizeof(buffer2));
	fflush(stdin);
	int i,j,k,sum;
	printf("Matrix received");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t", buffer[i][j]);
		}
		printf("\n\n");
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t", buffer2[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
	int result[2][2];
	for (i = 0; i < 2; i++) {
      		for (j = 0; j < 2; j++) {
			sum = 0;
        		for (int k = 0; k < 2; k++) {
          			sum = sum + buffer[i][k]*buffer2[k][j];
        }
        result[i][j] = sum;
      }
      printf("\n");
    }
    
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t", result[i][j]);
		}
		printf("\n");
	} 
	close(fd);
	close(fd2);
	return 0;
}
