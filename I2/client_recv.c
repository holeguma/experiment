#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

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
    int n;
    if (ret == -1)
        die("connect");
    char c;
    while (1)
    {
        n = recv(s, &c, 1, 0);
        if (n == -1)
            die("recv");
        if (n == 0)
            break;
        write(1, &c, 1);
    }
    close(s);
    return 0;
}