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
    char c;
    while (scanf("%c", &c) != EOF)
    {
        send(s, &c, 1, 0);
    }
    close(s);
    return 0;
}