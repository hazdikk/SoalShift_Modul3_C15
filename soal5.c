#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_t t[50];
int status=0;

void *cari(void *arg){
	FILE* f;
	f=fopen("Novel.txt", "r");
	char search[100];
	int flag=0;
	char novel[100];
	strcpy(search, arg);
	while(fscanf(f, "%s", novel)!=EOF){
		if(strstr(novel, search) != NULL)	flag++;
	}
	fclose(f);
	printf("%s : %d\n", search, flag);
}

int main(int argc, char *argv[]){
	int i;
	for(i=1; i<=argc; i++){
		pthread_create(&(t[i]), NULL, &cari, (void*)argv[i]);
	}
	for(i=1; i<=argc; i++){
		pthread_join(t[i], NULL);
	}
}
