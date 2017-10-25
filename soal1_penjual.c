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


