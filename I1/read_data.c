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
    FILE* fp=fopen(argv[2],"wb");
    int fd=open(argv[1],O_RDONLY);
    int n;
    if(fd==-1){
        die("open");
    }
    unsigned char data[256];
    int count=0;
    while(1){
        n=read(fd,data,256);
        if(n==-1){
            die("read");
        }
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            fprintf(fp,"%d %d\n",count+i,data[i]);
        }
        count+=n;
    }
    return 0;
}