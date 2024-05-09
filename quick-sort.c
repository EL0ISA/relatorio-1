#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void quick_sort(int v[], int s, int e);
int partition(int v[], int s, int e);
void trocar(int vetor[], int pos1, int pos2);

int main(int argc, char **argv) {

    int vetor[5] = {7, 4, 3, 9, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    quick_sort(vetor,0,4);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
void trocar(int vetor[], int pos1, int pos2) {
    int temp = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = temp;
}
void quick_sort(int v[], int s,int e){
    if (s<e) {
        int p=partition(v, s, e);
        quick_sort(v,s,p-1);
        quick_sort(v,p+1,e);
    }
}
int partition(int v[], int ini, int fim){
    int p=fim;
    int d=ini-1;//? pq isso? sendo que no caderno ta de outro jeito...
    for (int i = ini; i <=(fim-1); i++) {
        if (v[i]<=v[p]) {
            d=d+1;
            trocar(v,i,d);
        }   
    }
    trocar(v,d+1,p);
    return d+1;
}