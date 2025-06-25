/*Implement a thread function that takes an integer argument, squares it, and returns the result to the main thread using 
pthread_exit and pthread_join.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *square(void *arg) {
    int num = *(int *)arg;
    int *result = malloc(sizeof(int));  // allocate memory for the result
    if (result == NULL) {
        perror("malloc failed");
        pthread_exit(NULL);
    }
    *result = num * num;
    pthread_exit(result);  // return the result pointer
}

int main() {
    pthread_t thread;
    int number = 7;
    int *result;

    // Create thread and pass the address of number
    pthread_create(&thread, NULL, square, &number);

    // Wait for the thread to finish and get the result
    pthread_join(thread, (void **)&result);

    if (result != NULL) {
        printf("Square of %d is %d\n", number, *result);
        free(result);  // free allocated memory
    } else {
        printf("Thread did not return a result\n");
    }

    return 0;
}


//Output:
Square of 5 is 25
