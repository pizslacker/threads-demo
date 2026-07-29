#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // The POSIX thread library
#include <unistd.h>  // Included for the sleep() function

// A structure to pass multiple arguments into our thread function
typedef struct {
    int thread_id;
    const char *message;
} ThreadData;

// The function that each thread will execute.
// It must return void* and take a single void* argument.
void *thread_function(void *arg) {
    // 1. Cast the generic void pointer back to our specific struct type
    ThreadData *data = (ThreadData *)arg;

    printf("--> Thread %d starting: %s\n", data->thread_id, data->message);
    
    // 2. Simulate some work with a loop and sleep
    // Because both threads run concurrently, you will see their output mix together.
    for (int i = 1; i <= 3; i++) {
        printf("Thread %d working... (step %d/3)\n", data->thread_id, i);
        sleep(1); 
    }

    printf("<-- Thread %d finished.\n", data->thread_id);
    
    // 3. Return NULL to satisfy the void* return requirement
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    // Define the data we want to pass to each thread
    ThreadData data1 = {1, "Hello from the first thread!"};
    ThreadData data2 = {2, "Greetings from the second thread!"};

    printf("Main program starting.\n\n");

    // --- STEP 1: Create the threads ---
    // pthread_create arguments: 
    // &thread1        - Pointer to our pthread_t variable
    // NULL            - Thread attributes (NULL means default)
    // thread_function - The function the thread should run
    // &data1          - The argument to pass to the function
    if (pthread_create(&thread1, NULL, thread_function, &data1) != 0) {
        perror("Failed to create thread 1");
        return EXIT_FAILURE;
    }

    if (pthread_create(&thread2, NULL, thread_function, &data2) != 0) {
        perror("Failed to create thread 2");
        return EXIT_FAILURE;
    }

    // --- STEP 2: Wait for threads to finish ---
    // If we don't call pthread_join, the main function might finish and exit
    // the entire program before the threads get a chance to complete their work.
    if (pthread_join(thread1, NULL) != 0) {
        perror("Failed to join thread 1");
        return EXIT_FAILURE;
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("Failed to join thread 2");
        return EXIT_FAILURE;
    }

    printf("\nMain program finishing. Both threads are successfully joined.\n");

    return EXIT_SUCCESS;
}
