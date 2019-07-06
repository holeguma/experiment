#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){
    puts(argv[1]);
    int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644);
    unsigned char data[256];
    for(int i=0;i<256;i++){
        data[i]=i;
    }
    write(fd,data,256);
    close(fd);
    return 0;
}