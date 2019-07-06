#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#define N 4000

void die(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char **argv)
{
    int port = atoi(argv[1]);
    int s = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("192.168.100.129");
    addr.sin_port = htons(port);
    int ret = connect(s, (struct sockaddr *)&addr, sizeof(addr));
    unsigned char c1[N];
    unsigned char c2[N];
    int n, m;
    FILE *play = popen("play -t raw -b 16 -c 1 -e s -r 44100 -", "w");
    FILE *rec = popen("rec -t raw -b 16 -c 1 -e s -r 44100 -", "r");
    while (1)
    {
        n = fread(c1, 1, N, rec);
        m = recv(s, c2, N, 0);
        if (n == -1 || m == -1)
        {
            break;
        }
        n = send(s, c1, n, 0);
        m = fwrite(c2, 1, m, play);
        if (n == -1 || m == -1)
        {
            break;
        }
    }
    pclose(rec);
    pclose(play);
    close(s);
    return 0;
}