# include <stdio.h>
# include <pthread.h>

void * thread_sum(void *);
int TotalSum=1;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{
    int iNumber,iCount;
    pthread_t tid;
    printf("Enter Number Up to Which You want to Sum :");
    scanf("%d",&iNumber);
    pthread_create(&tid,NULL,thread_sum,(void *)&iNumber);

    pthread_join(tid,NULL);

    printf("Final Sum is : %d \n",TotalSum);
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
	printf("%d\n", TotalSum);
    }
    pthread_exit(NULL);
}
