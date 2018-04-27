#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd, retval;
	int fd2, retval2;
	int buffer[2][2] = {{1,2},{3,4}};
	int buffer2[2][2] = {{5,6},{7,8}};
	
	fflush(stdin);
	retval = mkfifo("/tmp/myfifo",0666);
	retval2 = mkfifo("/tmp/myfifos",0666);
	fd = open("/tmp/myfifo",O_WRONLY);
	fd2 = open("/tmp/myfifos",O_WRONLY);
	write(fd,buffer,sizeof(buffer));
	write(fd2,buffer2,sizeof(buffer2));	
	close(fd);
	close(fd2);
	return 0;
}
