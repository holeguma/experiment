#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

int min(int a,int b){
    if(a>b) return b;
    return a;
}

int main(int argc, char** argv){
    int A=atoi(argv[1]);
    int n=atoi(argv[2]);
    short int data[n];
    double f[]={261.626,293.665,329.628,349.228,391.995,440,493.883};
    int count=0;
    int nn=n;
    while(n>0){
        for(int i=0;i<min(13230,n);i++){
           data[nn-n+i]= A*sin(2.0*PI*f[count%7]*(1LL<<(count/7))*(nn-n+i)/44100);
        }
        n-=13230;
        count++;
    }
    write(1,data,2*nn);
    return 0;
}