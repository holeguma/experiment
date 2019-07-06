#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd=open("hitoshi",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd==-1){
        perror("open");
        exit(1);
    }
    unsigned char data[6]={228,186,186,229,191,151};
    write(fd,data,6);
    close(fd);
    return 0;
}