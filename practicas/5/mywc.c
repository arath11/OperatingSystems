#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    char c;
    unsigned total = 0;
    unsigned linea = 0;
    unsigned palabra = 0;
    unsigned caracteres = 0;
    unsigned i=0;
    char buffer[250];
    //palabra  linea y caracteres 
    //linea++;
    while(read(STDIN_FILENO,&c,1)!=0){
        //cuando es diferente a salto de linea o salto de pagina 
        if(c != ' ' && c != '\n'){
            buffer[i++] = c;
            caracteres++;            
        }else if(c == '\n'){
            linea++;
            caracteres++;

            //palabra++;
        }else{
            caracteres++;
            palabra++;
            buffer[i]='\0';   
        }
    }
    buffer[i]='\0';
    
    
    
    printf("%u\n",linea);
    printf("%u\n",palabra);
    printf("%u\n",caracteres);
        //write(STDOUT_FILENO, &c,1);
    return 0;
//    printf("El contenido es: %s\n",name);
}