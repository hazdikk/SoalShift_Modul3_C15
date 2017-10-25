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

while()
{

}

else{
return 0;
}

