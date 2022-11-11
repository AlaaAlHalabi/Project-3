#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#define BUFFERSIZE 80
int main(){
  int clientSock, status;
  char input[BUFFERSIZE] = "";
  char recvBuf[BUFFERSIZE];
    if((clientSock = socket(PF_INET, SOCK_STREAM,0)) < 0) perror("");
    struct sockaddr_in serverSock;
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(5001);
    serverSock.sin_addr.s_addr = inet_addr("127.0.0.1");
    if((status = connect(clientSock, (struct sockaddr *)&serverSock, sizeof(serverSock))) < 0) perror("");
    printf("Enter your request \n");
    scanf("%s", input);
    if((send(clientSock, input, sizeof(input),0)) != sizeof(input)) perror("sent a different number of bytes");
    if((recv(clientSock, recvBuf, BUFFERSIZE,0)) <= 0) perror("recv()failed or connection lost prematurley");
    printf("%s\n", recvBuf); 
    close(clientSock);
  return 0;
}
