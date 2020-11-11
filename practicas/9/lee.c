#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
    int fd=open("./lee.c",O_RDONLY,0); // abrir archivos fopen 
    if(fd<0){
        printf("Error al abrir el archivo ");
        return 1;
    }
    char c;
    while(read(fd,&c, 1)){
        printf("%c",c);
    }
  return 0;

}