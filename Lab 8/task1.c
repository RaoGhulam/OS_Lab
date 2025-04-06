#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_OF_THREADS 10
#define ARRAY_SIZE 1000000
float arr_A[ARRAY_SIZE];
float arr_B[ARRAY_SIZE];
float arr_C[ARRAY_SIZE];

void generate_arrays(){
    for(int i=0; i<ARRAY_SIZE; i++){
        arr_A[i] = rand() % 1000;
        arr_B[i] = rand() % 1000;
    }
}

void serial_code(){
    for(int i=0; i<ARRAY_SIZE; i++){
        arr_C[i] = arr_A[i] + arr_B[i];
    }
}

void* concurrent_code(void *t){
    long thread_id = (long)t;
    long start = thread_id * ARRAY_SIZE / NUM_OF_THREADS;
    long end = (thread_id == NUM_OF_THREADS - 1) ? ARRAY_SIZE : start + ARRAY_SIZE / NUM_OF_THREADS;
    for(long i = start; i < end; i++){
        arr_C[i] = arr_A[i] + arr_B[i];
    }
    pthread_exit(NULL);
}

void print_array(){
    for (int i=0; i<100; i++){
        printf("%f ", arr_C[i]);
    }
    printf("\n");
}

int main(){
    pthread_t threads[NUM_OF_THREADS];
    pthread_attr_t attr;

    generate_arrays();

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(long i = 0; i < NUM_OF_THREADS; i++){
        pthread_create(&threads[i], &attr, concurrent_code, (void *)i);
    }

    pthread_attr_destroy(&attr);
    
    for(long i = 0; i < NUM_OF_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    print_array();

    return EXIT_SUCCESS;
}