/*Write a program to create 5 threads. Each thread should print its thread ID and then exit. 
The main thread should join all threads and print a completion message. use pthread_self()-to get id.*/

#include <stdio.h>
#include <pthread.h>

void* printThreadID(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, printThreadID, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All 5 threads have finished.\n");
    return 0;
}


//Output:
Thread ID: 123884642838208
Thread ID: 123884634445504
Thread ID: 123884626052800
Thread ID: 123884617660096
Thread ID: 123884609267392
All 5 threads have finished.
