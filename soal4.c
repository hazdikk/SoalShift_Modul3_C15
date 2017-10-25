# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

void * thread_sum(void *);
int TotalSum=1;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[])
{
    int i=1;
    for(i=1;i<=argc;i++){
	TotalSum=1;
    	int iNumber,iCount;
    	pthread_t tid;
	iNumber = atoi(argv[i]);
	//scanf("%d", &iNumber);
    	pthread_create(&tid,NULL,thread_sum,(void *)&iNumber);

    	pthread_join(tid,NULL);

    	printf("Final Sum is : %d \n",TotalSum);
    }
//    return 0;
}

void *thread_sum(void *no)
{
    int *iNumber,iCount;
    iNumber=(int*)no;

    for(iCount=1;iCount<=*iNumber;iCount=iCount+1)
    {
        pthread_mutex_lock(&mVar);
        TotalSum=TotalSum * iCount;
        pthread_mutex_unlock(&mVar);
    }
    pthread_exit(NULL);
}
