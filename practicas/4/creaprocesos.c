//#include <cstddef>
//#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void signalHandler(int signum){
    int status;
    wait(&status);
    printf("Limpieando la memoria que pudo dejar el hijo %d",status);
}

int main(int argc, char *argv[]){
    signal(17, signalHandler);
    unsigned pid = fork();
    if(pid == 0){
        sleep(5);
        printf("Soy el proceso hijo\n");
        return 10;
    }else {
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        while (1) {
        sleep(2);    
            printf("Trabajando\n");
        }
    }
    printf("Hola mundo \n");
    return 0;
}
