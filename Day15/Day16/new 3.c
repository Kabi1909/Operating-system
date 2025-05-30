#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function for first child thread
void* first_child(void* arg) {
    sleep(1);
    printf("First child: Slept for 1 second\n");
    return NULL;
}

// Function for second child thread
void* second_child(void* arg) {
    sleep(3);
    printf("Second child: Slept for 3 seconds\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Creating child threads
    pthread_create(&t1, NULL, first_child, NULL);
    pthread_create(&t2, NULL, second_child, NULL);

    // Waiting for both threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Parent: Both children have finished\n");

    return 0;
}




//Exercise02:
//First Child: sleep for 2 seconds, exit with status 2.
//Second chid: sleep for 1 seconds, exits with status 1.
//parent: waits twice, and prints which child (by PID or exit code)
//finished first and second.