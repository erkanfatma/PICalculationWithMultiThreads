/* @author Fatma Erkan */

//to run:   
// 1. gcc picalculation.c -lm -o picalc -pthread
// 2. ./picalc

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <pthread.h>

#define CONSTANT_PI 3.1415926535897932384626433832
double *opr_results;
pthread_t *threads;

typedef struct Part{
    int index_val;
    int first_val;
    int opr_count;
}Part;


double operation(int arg){
    int denm = (2 * arg +1) * (int)pow(-1.0, (double)arg);
    double result = 1.0 / denm;
    //printf(" + 1/%d ", denm);
    return result;
}

void *worker(void *arg){
    double result = 0.0; 
    Part part1 = *(struct Part *)arg;
    
    for (int i = 0; i < part1.opr_count; i++) {
        int temp_val = part1.first_val + i;
        result = result + operation(temp_val);
    } 
    opr_results[part1.index_val] = result;
    
}


int main(int argc, char argv[]){
    int thread_num, opr_num;
    struct timeval start,stop;
    double calculated_pi;

    //Number of threads 
    printf("\tEnter the number of threads: ");
    scanf("%d", &thread_num);
    threads = (pthread_t*)malloc(sizeof(pthread_t) * thread_num);

    //Number of operations 
    printf("\tEnter the number of operations: ");
    scanf("%d", &opr_num);
    opr_results = (double *)malloc(sizeof(double) * opr_num);
 
    //Begin time
    gettimeofday(&start, NULL);
    printf("\tCalculating ...\n\n");
    
    //printf("\tOperations: \n");

    //Thread operations
    int part_count = opr_num / thread_num;
    int end_opr = -1;

    for (int i = 0; i < thread_num; i++) {
        Part pt;
        pt.first_val = end_opr + 1;
        pt.index_val = i;
        if (i + 1 == thread_num) {
            pt.opr_count = part_count + (opr_num % thread_num);
        }else{
            pt.opr_count = part_count;
        }

        end_opr = pt.first_val + pt.opr_count - 1;

        pthread_create(&threads[i], NULL, worker, &pt); 
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < thread_num; i++) {
        pthread_join(threads[i], NULL);
    }
        
    //PI calculation
    for (int i = 0; i < thread_num; i++) {
        calculated_pi += opr_results[i];
    }
    calculated_pi = calculated_pi * 4;

    //printf("\n");

    //End time
    gettimeofday(&stop, NULL);
 

    //Results
    printf("\tResults\n");
    printf("\tActual PI number: \t %0.15f \n", CONSTANT_PI);
    printf("\tCalculated PI number: \t %0.15f \n", calculated_pi);
    double approximation_error = CONSTANT_PI - calculated_pi;
    printf("\tApproximation Error: \t %0.15f \n", approximation_error);
    printf ("\tElapsed time : %f seconds\n", (double) (stop.tv_usec - start.tv_usec) / 1000000 + (double) (stop.tv_sec - start.tv_sec));

}