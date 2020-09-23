//#include <cstddef>
//#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    unsigned pid = fork();
    if(pid == 0){
        char *newenviron[] = { NULL };
        printf("Soy el proceso hijo\n");
        execv(argv[1], &argv[1]);
        return 10;
    }else {
        int status;
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        //sleep(1);
        //esta funcion espera a que el hijo corra 
        //le pasamos la direccion de status con &
        wait(&status);
        printf("Terminando despues del hijo y estutus  %d\n",status);
    }
    printf("Hola mundo \n");

    return 0;

    //primera parte 
    //fork();
    //fork();
    //printf("Hola mundo \n");
    //return 0;
}