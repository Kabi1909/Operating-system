/*Write a C program that creates two threads. Each thread should print a message indicating it is running. 
The main thread should wait for both threads to finish before exiting. */

#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg){
	int threadNum = (int*)arg;
	printf("Thread %d is running\n",threadNum);
	return NULL;
}

int main(){
	pthread_t thread1, thread2;
	int t1_id = 1, t2_id = 2;
	
	pthread_create(&t1, NULL, threadFunc, &t1_id);
	pthread_create(&t2, NULL, threadFunc, &t2_id);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("Both are completed\n");
	return 0;
}


//Output:
Thread 1 is running
Thread 2 is running
Both are completed
