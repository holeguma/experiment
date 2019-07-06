#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#define N 128

void die(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char **argv)
{
    int port = atoi(argv[1]);
    int ss = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    int ret = bind(ss, (struct sockaddr *)&addr, sizeof(addr));
    listen(ss, 10);
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    int s = accept(ss, (struct sockaddr *)&client_addr, &len);
    unsigned char c[N];
    int n, m;
    FILE *play = popen("play -t raw -b 16 -c 1 -e s -r 44100 -", "w");
    FILE *rec = popen("rec -t raw -b 16 -c 1 -e s -r 44100 -", "r");
    // int start = 0;
    while (1)
    {
        fread(c, 1, N, rec);
        n = send(s, c, N, 0);
        m = recv(s, c, N, 0);
        fwrite(c, 1, N, play);
        if (n == -1 || m == -1)
        {
            /*        if (!start)
            {
                start |= 1;
                continue;
            }
            else*/
            break;
        }
    }
    pclose(rec);
    pclose(play);
    close(s);
    close(ss);
    return 0;
}