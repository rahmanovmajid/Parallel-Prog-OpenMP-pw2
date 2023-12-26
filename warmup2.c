/* Fahmin Guliyev */

#include <stdio.h>
#include <omp.h>

int main() {
    
    int i, tid;
    #pragma omp parallel private(tid)
    {   
        tid = omp_get_thread_num();
        #pragma omp for
        for (i = 0; i < 20; i++) {
            printf("Thread nb %d executes index=%d \n",tid,i);
        }
    }
    
    return 0;
}

/*

To dynamically adjust the number of threads, set the value of the OMP_NUM_THREADS
environment variable and observe the changes when the loop is executed.

*/