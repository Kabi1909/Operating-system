/*Create two threads where one thread increments a global counter 100 times and the other thread decrements the same counter 100 times.
Print the final value of the counter after both threads finish.*/

#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *increment(void *arg) {
    for (int i = 0; i < 100; i++) {
        counter++;
    }
    return NULL;
}

void *decrement(void *arg) {
    for (int i = 0; i < 100; i++) {
        counter--;
    }
    return NULL;
}

int main() {
    pthread_t inc_thread, dec_thread;

    pthread_create(&inc_thread, NULL, increment, NULL);
    pthread_create(&dec_thread, NULL, decrement, NULL);

    pthread_join(inc_thread, NULL);
    pthread_join(dec_thread, NULL);

    printf("Final value of counter: %d\n", counter);

    return 0;
}

//Output:
Final value of counter: 0
