/*****************************************************
三个线程，依次打印ABC，打印十次，互斥锁，信号量
*****************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *process1(void * arge);
void *process2(void * arge);
void *process3(void * arge);

pthread_mutex_t mux;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;

int main()
{
	pthread_t id1,id2,id3;

	pthread_cond_init(&cond1,NULL);
	pthread_cond_init(&cond2,NULL);
	pthread_cond_init(&cond3,NULL);

	pthread_mutex_init(&mux,0);

	pthread_create(&id1,NULL,process1,(void *)NULL);
	pthread_create(&id2,NULL,process2,(void *)NULL);
	pthread_create(&id3,NULL,process3,(void *)NULL);

	sleep(1);

	pthread_cond_signal(&cond1);

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_join(id3,NULL);

    return 0;
}

void * process1(void * arge)
{
	int i;

	for(i=0;i<10;i++)
	{
		pthread_mutex_lock(&mux);
		pthread_cond_wait(&cond1,&mux);
		printf("A");
		pthread_mutex_unlock(&mux);
		pthread_cond_signal(&cond2);
	}

}


void * process2(void * arge)
{
	int i;

	for(i=0;i<10;i++)
	{
		pthread_mutex_lock(&mux);
		pthread_cond_wait(&cond2,&mux);
		printf("B");
		pthread_mutex_unlock(&mux);
		pthread_cond_signal(&cond3);
	}
}

void * process3(void * arge)
{
	int i;

	for(i=0;i<10;i++)
	{
		pthread_mutex_lock(&mux);
		pthread_cond_wait(&cond3,&mux);
		printf("C");
		pthread_mutex_unlock(&mux);
		pthread_cond_signal(&cond1);
	}
}














