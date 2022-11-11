#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#define MAXPENDING 5
#define BUFFERSIZE 80


int main(){
 
  int serverSock, status, clientSock, clientLen, recvMsgSize,r,b,i;
  char recvBuf[BUFFERSIZE];
  if((serverSock=socket(PF_INET, SOCK_STREAM, 0)) < 0) perror("");
  struct sockaddr_in serverSockAddr, clientSockAddr;
  memset(&serverSockAddr, 0, sizeof(serverSockAddr));
  serverSockAddr.sin_family = AF_INET;
  serverSockAddr.sin_port = htons(5001);
  serverSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  if(bind(serverSock, (struct sockaddr *)&serverSockAddr, sizeof(serverSockAddr)) < 0) perror("");
  if((status = listen(serverSock, MAXPENDING)) < 0) perror("");
  printf("Server is waiting for a connection.....\n");
  for(;;){
    clientLen = sizeof(clientSockAddr);
    if((clientSock = accept(serverSock, (struct sockaddr *)&clientSockAddr, &clientLen)) < 0) perror("");
    printf("A new connection established\n");
    
    if((recvMsgSize = recv(clientSock, recvBuf, BUFFERSIZE, 0)) < 0) perror("recv() failed");
    

      r=strcmp(recvBuf,"time");
b=strcmp(recvBuf,"date");
      if(r==0){
for (i=1;i<=100;i++)
	{

sleep(1);
        time_t rawtime; 
        struct tm* timeinfo; 
         char buffer[80]; 
        time(&rawtime); 
        timeinfo = localtime(&rawtime); 
        strftime(buffer, 80,"Time is %I:%M%p.", timeinfo); 
        strcpy(recvBuf, buffer);
             
        if((send(clientSock,recvBuf, recvMsgSize, 0)) < 0) perror("send() failed");}
        
     close(clientSock);
    printf("\n");}

if(b==0){
for (i=1;i<=100;i++)
	{
sleep(1);
 struct tm* ptr; 
    time_t t; 
    t = time(NULL); 
    ptr = localtime(&t); 
     
strcpy(recvBuf, asctime(ptr));
if((send(clientSock,recvBuf, recvMsgSize, 0)) < 0) perror("send() failed");}




             
     close(clientSock);
    printf("\n");}
  }
return 0;
}
