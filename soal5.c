#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_t t[50];

void *cari(void *arg){
	FILE* f;
	f=fopen("Novel.txt", "r");
	char search[100];
	int flag;
	char novel[100];
	while(fscanf(f, "%s", novel)!=EOF){
		
	}
}

int main(int argc, char *argv[]){
	int i;
	for(i=1; i<=argc; i++){
		pthread_create(&(t[i]), NULL, &cari, (void*)argv[i]);
		printf("%s\n", argv[i]);
	}
}
