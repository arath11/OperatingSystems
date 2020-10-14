#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct hd{
	int hid;
	char *msg;
} ThreadData;



void * hello(void *arg){
	ThreadData *td =(ThreadData *)arg;
	printf("%s %d\n",td->msg, td->hid);
	//printf("Hello desde el hilo\n");
	free(arg);
	pthread_exit(NULL);
}

int main(){
	pthread_t newThread;
	//ThreadData td[10];
	for(int i =0; i<10; i++){
		ThreadData *td = (ThreadData *)calloc(1,sizeof(ThreadData));	//cuantod quiero y de que tamaño 
		td->msg = "Helloo world";
		td->hid= i ;
		pthread_create(&newThread,NULL,hello,(void *) td);	
		//pthread_create(&newThread,NULL,hello,(void *) &td[i]);	
	}
	pthread_exit(NULL);
	return 0;	
}