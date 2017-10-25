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

struct Memory *barang;
int menu;
char nama_barang[99];
int tambahan;

sharedKEY = ftok("#", 'A');
sharedID = shmget(sharedKEY, sizeof(struct Memory), IPC_CREAT | 0666);

if (sharedID < 0){
printf("SHMGET ERROR!\n");
exit(1);
}

barang = (struct Memory *) shmat(sharedID, NULL, 0);
barang->status = BELUM_SIAP;

barang->MP4A1=0;
barang->PM2_V1=0;
barang->SPR_3=0;
barang->SS2_V5=0;
barang->SPG1_V3=0;
barang->MINE=0;

while(1)
{
printf("==Menu==\n");
printf("1. Lihat stock senjata\n");
printf("2. Tambah stock senjata\n");
printf(">> ");
scanf("%d", &menu);

if (menu == 1)
{
 if(barang->MP4A1>0){
 printf("Jumlah MP4A1 = %d\n", barang->MP4A1);
 }

 if(barang->PM2_V1>0){
 printf("Jumlah PM2-V1 = %d\n", barang->PM2_V1);
 }

 if(barang->SPR_3>0){
 printf("Jumlah SPR-3 = %d\n", barang->SPR_3);
 }

 if(barang->SS2_V5>0){
 printf("Jumlah SS2-V5 = %d\n", barang->SS2_V5);
 }

 if(barang->SPG1_V3){
 printf("Jumlah SPG1-V3 = %d\n", barang->SPG1_V3);
 }

 if(barang->MINE){
 printf("Jumlah MINE = %d\n", barang->MINE);
 }

 else{
 printf("STOK HABIS\n\n");
 }
}

else if(menu == 2){
printf("\nPilih Barang yang akan ditambahkan!\n");
printf("FORMAT INPUT : [NAMA_BARANG] [JUMLAH_BARANG]\n");
printf("1. MP4A1\n2. PM2-V1\n3. SPR-3\n4. SS2-V5\n5. SPG1-V3\n6. MINE\n");
printf(">> ");
scanf("%s %d", nama_barang, &tambahan);

if (strcmp(nama_barang,"MP4A1")==0){
barang->MP4A1 += tambahan;
printf("Jumlah stock MP4A1 = %d \n", barang->MP4A1);
}

if (strcmp(nama_barang,"PM2-V1")==0){
barang->PM2_V1 += tambahan;
printf("Jumlah stock PM2-V1 = %d \n", barang->PM2_V1);
}

if (strcmp(nama_barang,"SPR-3")==0){
barang->SPR_3 += tambahan;
printf("Jumlah stock SPR-3 = %d \n", barang->SPR_3);
}

if (strcmp(nama_barang,"SS2-V5")==0){
barang->SS2_V5 += tambahan;
printf("Jumlah stock SS2-V5 = %d \n", barang->SS2_V5);
}

if (strcmp(nama_barang,"SPG1-V3")==0){
barang->SPG1_V3 += tambahan;
printf("Jumlah stock SPG1-V3 = %d \n", barang->SPG1_V3);
}

if (strcmp(nama_barang,"MINE")==0){
barang->MINE += tambahan;
printf("Jumlah stock MINE = %d \n", barang->MINE);
}
}

else{
return 0;
}

getchar();

}
}
