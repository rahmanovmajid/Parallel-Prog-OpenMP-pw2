#include <stdio.h>
#include <omp.h>
#include <time.h>

#define SIZE 100
int main() {

    srand(time(NULL));

    int arr[SIZE], i;
    float avg = 0;

    #pragma omp parallel
    {
        #pragma omp for reduction(+:avg)
        for (int i = 0; i < SIZE; i++) {
            arr[i] = rand()%10;
            avg += arr[i];
        }
        avg /= SIZE;
        printf("Thread %d is working...\n", omp_get_thread_num());
    }
    
    printf("Finally, the average of elements in the array is %.2f\n",avg);
    return 0;
}