#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    char c;
    unsigned total = 0;
    unsigned i=0;
    char buffer[250];
    while(read(STDIN_FILENO,&c,1)!=0){
        if(c != ' '){
            buffer[i++] = c;
            
        }else{
            buffer[i]='\0';
            total += atoi(buffer);
            i=0;
        }
    }
    buffer[i]='\0';
    total += atoi(buffer);
    i=0;
    
    
    printf("%u\n",total);
        //write(STDOUT_FILENO, &c,1);
    return 0;
//    printf("El contenido es: %s\n",name);
}