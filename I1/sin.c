#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

int main(int argc, char** argv){
    int A=atoi(argv[1]);
    int f=atoi(argv[2]);
    int n=atoi(argv[3]);
    short int data[n];;
    for(int i=0;i<=n-1;i++){
       data[i]= A*sin(2.0*PI*f*i/44100);
      // data[i+n]= A*sin(2.0*PI*f*i/44100);
    }
    write(1,data,2*n);
    return 0;
}