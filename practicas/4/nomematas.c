#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void signalHandler(int signum){
    printf("JAJAJ no me matas \n");
    
}


int main(){
    signal(2, signalHandler);
    while (1) {
        sleep(2);
        printf("Trabajando \n");
    }
    return 0;
}