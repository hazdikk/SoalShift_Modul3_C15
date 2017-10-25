#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t t[50];

void *cari(void *);

int main(int argc, char *argv[]){
	int i;
	for(i=1; i<=argc; i++){
		pthread_create(&(t[i]), NULL, &cari, (void*)argv[i]);
	}
}
