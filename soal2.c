
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    

    pthread_create(&(tid1), NULL, &playandcount, NULL);
    pthread_create(&(tid2), NULL, &playandcount, NULL);
    while(1){
    	
    }
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}
