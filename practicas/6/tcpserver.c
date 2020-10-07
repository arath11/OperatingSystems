#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main(){
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(2727);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int sockfd =socket(AF_INET, SOCK_STREAM,0);
    bind(sockfd,&serverAddress,sizeof(serverAddress));
    listen(sockfd, 0);
    while(1){
        struct sockaddr_in clientAddress;
        int clientSize = sizeof(clientAddress);
        int clientSocket = accept(sockfd,&clientAddress, &clientSize);
        char c;
        char *message = "hello desde gitpod";
        //while (read(clientSocket,&c, 1)) {
          //  printf("%c",c);
//            write(clientSocket,&c,1);
  //      }   

        write(clientSocket,message,strlen(message));
        close(clientSocket);
    }

}