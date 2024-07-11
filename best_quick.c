#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void best(int v[], int s, int e);
void trocar(int vetor[], int pos1, int pos2);
void merge_sort(int v[], int s, int e);
void merge(int v[], int s, int m, int e);
int main(int argc, char **argv) {
    int array[8];
    for (int j = 0; j < 8; j++) {
        array[j] = rand() % 100;
    }
    for(int i = 0; i <8; i++) {
        printf("%d ", array[i]);
    }
    merge_sort(array,0,7);
     printf("\n ");
    for(int i = 0; i <8; i++) {
        printf("%d ", array[i]);
    }
    best(array,0, 7);
    printf("\n ");
    for(int i = 0; i <8; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
void best(int v[], int s, int e) {
    if(s<e){
        int m= (s+e)/2;
        best(v,s,m-1);
        best(v,m+1,e);
        trocar(v,m,e);    
    }
}
void trocar(int vetor[], int pos1, int pos2) {
    int temp = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = temp;
}
void merge_sort(int v[], int s,int e){
    if (s<e) {
        int m=(s+e)/2;
        merge_sort(v,s,m);
        merge_sort(v,m+1,e);
        merge(v,s,m,e);
    }
}
void merge(int v[], int s, int m, int e){
    int i=s;
    int j=m+1;
    int vetorAux[e-s+1];
    for(int k=0; k < (e-s+1);k++){
        if((i<=m)&& ((j>e)|| v[i]<v[j])){
            vetorAux[k]=v[i];
            i=i+1;
        }else{
            vetorAux[k]=v[j];
            j=j+1;
        }
    }
    for (int k = 0; k <= (e-s); k++) {
        v[s+k]=vetorAux[k];
    }
}