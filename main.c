//https://blog.csdn.net/hnlgzb/article/details/126900638
//https://blog.csdn.net/qq_15437629/article/details/77429868

#pragma comment(lib, "pthreadVC2.lib")
#include<string.h>
#include<stdio.h>
#include <windows.h>
#include<string.h>
#include <pthread.h>
#include "unistd.h"
#define MAX 10

pthread_t thread[2];
pthread_mutex_t mut;
int number = 0;

void thread1() {
	printf("Thread 1: thread 1, starting...\n");
	for (int i = 0; i < MAX; i++) {
		pthread_mutex_lock(&mut);
		number++;
		pthread_mutex_unlock(&mut);
		printf("thread 1: number = %d\n", number);
		//Sleep(2000);
	}
	pthread_exit(NULL);
}

void thread2() {
	printf("Thread 2: thread 2, starting...\n");
	for (int i = 0; i < MAX; i++) {
		pthread_mutex_lock(&mut);
		number++;
		pthread_mutex_unlock(&mut);
		printf("thread 2: number = %d\n", number);
		//Sleep(3000);
	}
	pthread_exit(NULL);
}

void thread_create(void) {
	int temp;
	//memset(&thread, 0, sizeof(thread));
	if ((temp = pthread_create(&thread[0], NULL, (void*)thread1, NULL)) != 0) {
		printf("create thread1 failed");
	}
	else {
		printf("create thread1 successed\n");
	}
	if ((temp = pthread_create(&thread[1], NULL, (void*)thread2, NULL)) != 0) {
		printf("create thread2 failed");
	}
	else {
		printf("create thread2 successed\n");
	}
}


void thread_wait(void)
{
	/*等待线程结束*/
	//comment4    
	pthread_join(thread[0], NULL);
	printf("thread1 end !\n");
	//comment5
	pthread_join(thread[1], NULL);
	printf("thread2 end !\n");
}


int main(void) {
	pthread_mutex_init(&mut, NULL);
	thread_create();
	thread_wait();
	return 0;
}