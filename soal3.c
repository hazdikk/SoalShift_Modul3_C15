#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

<<<<<<< Updated upstream
int stats[2];
void *kepiting () {
	while (1) {

		sleep(20);
		stats[0] -= 10;
		if (stats[0] <= 0 || stats [0] > 100) {
			exit(EXIT_FAILURE);
		}
	}
}
void *lohan () {
	while (1) {

			sleep(20);
			stats[1] -= 10;
			if (stats[1] <= 0 || stats [1] > 100) {
				exit(EXIT_FAILURE);
			}
		}
}
void makan () {
	printf("hewan yang di berimakan\n1. kepiting\n2. Lohan\n");
	int a;
	scanf ("%d", &a);
	if (a==1) {
		stats [0]+=10;
		printf("Status kepiting bertambah %d\n", stats[0]);
	}
	else if (a==2) {
		stats [1]+=10;
		printf("Status lohan bertambah %d\n", stats[1]);
	}
	
=======
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
>>>>>>> Stashed changes
}
int main () 	{
	stats [0]=100;
	stats [1]=100;
	pthread_t kepiting_t, lohan_t;
	pthread_create (&kepiting_t,NULL,&kepiting,NULL);	
	pthread_create (&lohan_t,NULL,&lohan,NULL);

<<<<<<< Updated upstream
	while (1) {
		int pil;
		if(stats[1] <= 0 || stats[1] > 100 || stats[0] <= 0 || stats[0] > 100) {
			printf("Status lohan = %d\n", stats[0]);
			printf("Status kepiting = %d\n", stats[1]);
			printf("GAME OVER\n");
			exit(EXIT_FAILURE);
		}
		else {
			printf("1. Lihat status\n2. Berimakan\n");
			scanf ("%d",&pil);

			if (pil==1) {
				printf("Status Kepiting: %d\n", stats[0]);
				printf("Status Lohan: %d\n", stats[1]);
			}
			else if (pil==2) {
				makan();
			}
		}
}
=======
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
		}else	printf("input salah\n");
	}
>>>>>>> Stashed changes
}
