#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void insert_sort(int v[], int n);

void trocar(int vetor[], int pos1, int pos2) {
    int temp = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = temp;
}
int main(int argc, char **argv) {
    struct timespec a, b;
    unsigned int t;
    int vetor[5] = {7, 4, 3, 9, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    clock_gettime(CLOCK_MONOTONIC, &b);
    insert_sort(vetor,5);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
void insert_sort(int v[], int n){
    for(int i=1; i<n; i++){
        int j=i;
        while (j>0 && v[j]<v[j-1]){
            trocar(v,j,j-1);
            j=j-1;
        }
        
    } 
}