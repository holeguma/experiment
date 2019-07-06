#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void die(char* s){
    perror(s);
    exit(1);
}

int main(int argc, char** argv){
    puts(argv[1]);
    int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd==-1){
        die("open");
    }
    unsigned char data[256];
    for(int i=0;i<256;i++){
        data[i]=i;
    }
    int size=write(fd,data,256);
    if(size==-1){
        die("write");
    }
    close(fd);
    return 0;
}