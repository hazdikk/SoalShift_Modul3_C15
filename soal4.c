#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t t;
int num;
void* factorial()
{
	int fac=1;
	int a;
	for(a=1;a<=num;a++) 
	{
		fac=fac*a;
		printf("Factorial of Given Number is = %d", fac);
	}
}

int main()
{
	printf(" Enter Number To Find Its Factorial: ");
	scanf("%d", &num);
	pthread_create (&t,NULL,&factorial,(void*)&num);return 0;
}
