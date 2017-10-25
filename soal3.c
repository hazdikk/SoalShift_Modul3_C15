# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

int lohan;
int kepiting;

pthread_t t_k, t_l;

void* status(){
        printf("lalala");
        while(1){
                if(lohan <= 0 || lohan > 100 || kepiting <= 0 || kepiting > 100){
                        printf("Game Selesai");
                        exit(EXIT_FAILURE);
                }
                lohan = 103;
        }
}

int menu();

int main(){
     lohan=100, kepiting=100;
     int menu;
     pthread_create(&t_k, NULL, status, NULL);
     pthread_create(&t_l, NULL, status, NULL);
}
