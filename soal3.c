# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

int lohan;
int kepiting;

pthread_t t[5];

int status();
int menu();

int main(){
     int err[5];
     int menu;
     err[0]=pthread_create(&(t[0]), NULL, &status, NULL);
     err[1]=pthread_create(&(t[1]), NULL, &status, NULL);
}
