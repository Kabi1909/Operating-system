#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main() {
    size_t size = 3 * sizeof(long);
    long *shared_mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    int n, r;
    printf("Enter value for n: ");
    scanf("%d", &n);
    printf("Enter value for r: ");
    scanf("%d", &r);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process started (PID: %d)\n", getpid());

        long factorial(int num) { 
            long fact = 1;
			int i;
            for (i = 1; i <= num; i++)
                fact *= i;
            return fact;
        }

        shared_mem[0] = factorial(n);
        shared_mem[1] = factorial(r);
        shared_mem[2] = factorial(n - r);

        printf("Child calculated factorials and stored them in shared memory.\n");
        exit(0);
    } else {
        wait(NULL);
        long fact_n = shared_mem[0];
        long fact_r = shared_mem[1];
        long fact_n_r = shared_mem[2];

        long ncr = fact_n / (fact_r * fact_n_r);
        long npr = fact_n / fact_n_r;

        printf("Parent process started (PID: %d)\n", getpid());
        printf("Factorial of %d: %ld\n", n, fact_n);
        printf("Factorial of %d: %ld\n", r, fact_r);
        printf("NCR (%dC%d): %ld\n", n, r, ncr);
        printf("NPR (%dP%d): %ld\n", n, r, npr);

        munmap(shared_mem, size);
    }

    return 0;
}