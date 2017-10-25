#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#define BELUM_SIAP 0
#define SIAP 1

struct Memory{
int MP4A1, PM2_V1, SPR_3, SS2_V5, SPG1_V3, MINE, status;
};

int main(){
key_t sharedKEY;
int sharedID;

struct Memory barang;
int menu;
char nama_barang[101];
int total;

sharedKEY = ftok("#", 'A');
sharedID = shmget(sharedKEY, sizeof(struct Memory), IPC_CREAT | 0666);

if (sharedID < 0){
printf("SHMGET ERROR!\n");
exit(1);
}

barang = (struct Memory *) shmat(sharedID, NULL, 0);
barang.status = BELUM_SIAP;

barang.MP4A1=0;
barang.PM2_V1=0;
barang.SPR_3=0;
barang.SS2_V5=0;
barang.SPG1_V3=0;
barang.MINE=0;

while(1)
{
printf("==Menu==\n");
printf("1. Lihat stock senjata\n");
printf("2. Beli senjata\n");
printf(">> ");
scanf("%d", &menu);

if (menu == 1)
{
printf("Jumlah MP4A1 = %d\n", barang.MP4A1);
printf("Jumlah PM2-V1 = %d\n", barang.PM2_V1);
printf("Jumlah SPR-3 = %d\n", barang.SPR_3);
printf("Jumlah SS2-V5 = %d\n", barang.SS2_V5);
printf("Jumlah SPG1-V3 = %d\n", barang.SPG1_V3);
printf("Jumlah MINE = %d\n", barang.MINE);
}

else if(menu == 2){
printf("\nPilih Barang yang ingin Anda Beli!\n");
printf("FORMAT INPUT : [NAMA_BARANG] [JUMLAH_BARANG]\n");
printf("1. MP4A1\n2. PM2-V1\n3. SPR-3\n4. SS2-V5\n5. SPG1-V3\n6. MINE\n");
printf(">> ");
scanf("%s %d", nama_barang, &total);

if (strcmp(nama_barang,"MP4A1")==0){
 if (total > barang.MP4A1){
 printf("Barang di stock tidak cukup\n");
 }
 else{
 barang.MP4A1 -= total;
 }
}

if (strcmp(nama_barang,"PM2-V1")==0){
 if (total > barang.PM2_V1){
 printf("Barang di stock tidak cukup\n");
 }
 else{
 barang.PM2_V1 -= total;
 }

}

if (strcmp(nama_barang,"SPR-3")==0){
 if (total > barang.SPR_3){
 printf("Barang di stock tidak cukup\n");
 }
 else{
 barang.SPR_3 -= total;
 }
}

if (strcmp(nama_barang,"SS2-V5")==0){
 if (total > barang.SS2_V5){
 printf("Barang di stock tidak cukup\n");
 }
 else{
 barang.SS2_V5 -= total;
 }
}

if (strcmp(nama_barang,"SPG1-V3")==0){
 if (total > barang.SPG1_V3){
 printf("Barang di stock tidak cukup\n");
 }
 else{
 barang.SPG1_V3 -= total;
 }

}

if (strcmp(nama_barang,"MINE")==0){
 if (total > barang.MINE){
 printf("Barang di stock tidak cukup\n");
 }
 else{
 barang.MINE -= total;
 }
}

}

else{
return 0;
}

