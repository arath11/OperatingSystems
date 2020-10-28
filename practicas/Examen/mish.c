/******** mish.c **********/
// gcc -o mish mish.c
//estas son las librerias que usamos para el programa 
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

//son los limites de la funcion de parseo
#define MAX_LINE 80
#define MAX_NUM_ARGS 10
size_t string_parser(char *input, char *word_array[]) {
	size_t n = 0;
	while (*input) {
		while (isspace((unsigned char)*input))
			++input;
			if (*input) {
				word_array[n++] = (char *)input;
				while (*input && !isspace((unsigned char)*input))
					++input;
					*(input) = '\0';
					++input;
				}
			}
		word_array[n] = NULL;
		return n;
	}
 
//funcion principal 
int main(void) {
  char *args[MAX_NUM_ARGS + 1]; /* command line (of 80) has max of 5 arguments */
  char line[MAX_LINE + 1];
  //variable bandera para terminar o continuar 
  int should_run = 1;
  //contiene el numero de argumentos 
  int i;

  //ciclo principal
  while (should_run) {
    //"sobreescribe" promt
	printf("mish> ");
	//lee la entrada usando los limites definidos
    fgets(line,MAX_LINE,stdin);
	// cambia saltos de linea por caracter terminador
    line[strcspn(line, "\n")] = '\0';
	// Separamos la línea en palabras separadas por espacio
    // y las guardamos en args
    i = string_parser(line,args); // i contiene el número de argumentos
	
	// si el comando es exit, cambiar bandera y romper ciclo
	if(strcmp(line,"exit")==0){
		should_run=0;
		break;
	}
	
	// crear un proceso hijo mediante fork
	int pid = fork(); //
  	if (pid) {//padre o fork 
		int status;
		waitpid(pid,&status,0);
  	} else { // child
		// ejecutar otro programa en el proceso hijo
		execvp(line, &args[0]);
		// imprimir un error si el execvp fallo
		printf("El programa '%s' no existe\n", line);
		return 1;
  	}  
	  
    // vaciar la entrada y salida estandar
    fflush(stdout);
    fflush(stdin);
    line[0] = '\0';
  }

  // terminar el programa sin codigo de error
  return 0;
}
