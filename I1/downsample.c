#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

void die(char* s){
    perror(s);
    exit(1);
}

int main(int argc, char** argv){
    int n=atoi(argv[1]);
    short int data[n];
    int a;
    while(1){
        a=read(0,data,n*2);
        if(a==-1){
            die("read");
        }
        if(a==0){
            break;
        }
        write(1,data,2);   
    }
    return 0;
}