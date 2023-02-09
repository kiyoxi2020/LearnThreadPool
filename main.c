//https://blog.csdn.net/hnlgzb/article/details/126900638
//https://blog.csdn.net/qq_15437629/article/details/77429868

#pragma comment(lib, "pthreadVC2.lib")
#include<string.h>
#include<stdio.h>
#include<time.h>
#include <pthread.h>
#include "unistd.h"

void thread(void) {
	int i;
	for (i = 0; i < 3; i++) {
		printf("This is a pthread.\n");
	}
}

int main(void) {
	pthread_t id;
	int i, ret;
	ret = pthread_create(&id, NULL, (void*)thread, NULL);
	for (i = 0; i < 3; i++) {
		printf("This is the main process\n");
	}
	pthread_join(id, NULL);
	return 0;
}