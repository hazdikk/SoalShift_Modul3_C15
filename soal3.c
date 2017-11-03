# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
 
int lohan=100;
int kepiting=100;
int status=0;
pthread_t t_l, t_k;
 
void *status_kepiting(void *arg){
  status++;
        while(1){
                if(lohan <= 0 || lohan > 100 || kepiting <= 0 || kepiting > 100){
                        printf("Game Selesai\n");
                        exit(EXIT_FAILURE);
                }
    sleep(20);
    kepiting=kepiting-10;
        }
}
 
void *status_lohan(void *arg){
  status++;
        while(1){
                if(lohan <= 0 || lohan > 100 || kepiting <= 0 || kepiting > 100){
                        printf("Game Selesai\n");
                        exit(EXIT_FAILURE);
                }
    sleep(10);
    lohan=lohan-15;
        }
}

int main(){
       pthread_create(&t_k, NULL, &status_kepiting, NULL);
       while(status==0){
       }
       pthread_create(&t_l, NULL, &status_lohan, NULL);
       printf("Untuk memberi makan lohan ketik 1\n");
       printf("Untuk memberi makan kepiting ketik 2\n");
       printf("Untuk cek status lohan dan kepiting ketik 3\n");
       while(1){
        if(lohan <= 0 || lohan > 100 || kepiting <= 0 || kepiting > 100){
        printf("Status lohan = %d\n", lohan);
        printf("Status Kepiting =%d\n", kepiting);
        printf("Game Berakhir\n");
        exit(EXIT_FAILURE);
       }
       int menu=0;
       scanf("%d", &menu);
       if(menu == 1){
        lohan=lohan + 10;
        printf("Memberi makan lohan berhasil\n");
       }else if(menu == 2){
        kepiting=kepiting + 10;
        printf("Memberi makan kepiting berhasil\n");
       }else if(menu == 3){
        printf("Status lohan = %d\n", lohan);
        printf("Status Kepiting = %d\n", kepiting);
       }else  printf("input salah\n");
   }
}
