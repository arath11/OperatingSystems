#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    
char c;
    unsigned lineas =0;
    unsigned palabras =0;
    unsigned caracteres = 0;
    char buffer[250];
    unsigned i =0;

    //palabra  linea y caracteres 
    //linea++;
    while(read(STDIN_FILENO,&c,1)!=0){
        //cuando es diferente a salto de linea o salto de pagina 
        i++;
        buffer[i] = c;
        if (c!='\n'){
            caracteres++;
        }
        if(c==' '){
            if (buffer[i-1]!='\n' && buffer[i-1]!=' ' && i>1){
                palabras ++;
            }  
        } 
        else if (c=='\n'){
            lineas ++;
            if (buffer[i-1]!=' ' && i>1){
                palabras++;
            }
            i=0;
        }  
    }
    //buffer[i]='\0';
    caracteres=caracteres+lineas;
    printf("%u\n",lineas);
    printf("%u\n",palabras);
    printf("%u\n",caracteres);
    return 0;

} 