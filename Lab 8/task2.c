#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_OF_THREADS 3

typedef struct {
    int count;
    char **array;
} thread_args;

void* find_average(void *args) {
    thread_args *arg = (thread_args*)args;
    int total = 0;
    int avg;

    for(int i = 1; i < arg->count; i++) {
        total += atoi(arg->array[i]);
    }

    avg = total / (arg->count - 1);
    int* result = malloc(sizeof(int));
    *result = avg;

    pthread_exit((void*)result);
}

void* find_max(void *args) {
    thread_args *arg = (thread_args*)args;
    int max = 0;
    int val;

    for(int i = 1; i < arg->count; i++) {
        val = atoi(arg->array[i]);
        if(val > max) {
            max = val;
        }
    }

    int* result = malloc(sizeof(int));
    *result = max;

    pthread_exit((void*)result);
}

void* find_min(void *args) {
    thread_args *arg = (thread_args*)args;
    int min = 10000; 
    int val;

    for(int i = 1; i < arg->count; i++) { 
        val = atoi(arg->array[i]);
        if(val < min) {
            min = val;
        }
    }

    int* result = malloc(sizeof(int));
    *result = min;

    pthread_exit((void*)result);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Please provide command line input!\n");
        return 1;
    }

    pthread_t threads[NUM_OF_THREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    thread_args *args = malloc(sizeof(thread_args));
    args->count = argc;
    args->array = argv;

    pthread_create(&threads[0], &attr, find_average, (void*)args);
    pthread_create(&threads[1], &attr, find_max, (void*)args);
    pthread_create(&threads[2], &attr, find_min, (void*)args);
    
    pthread_attr_destroy(&attr);

    int* avg_result;
    int* max_result;
    int* min_result;

    pthread_join(threads[0], (void**)&avg_result);
    pthread_join(threads[1], (void**)&max_result);
    pthread_join(threads[2], (void**)&min_result);

    printf("Average: %d\n", *avg_result);
    printf("Max: %d\n", *max_result);
    printf("Min: %d\n", *min_result);

    free(avg_result);
    free(max_result);
    free(min_result);

    free(args);

    return 0;
}
