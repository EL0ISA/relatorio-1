#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void merge_sort(int v[], int s, int e);
void merge(int v[], int s, int m, int e);

int main(int argc, char **argv) {

    int vetor[5] = {7, 4, 3, 9, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    merge_sort(vetor,0,4);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
void merge_sort(int v[], int s,int e){
    if (s<e) {
        int m=(s+e)/2;
        printf("m:%d ",m);
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
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetorAux[i]);
    }
    for (int k = 0; k <= (e-s); k++) {
        v[s+k]=vetorAux[k];
    }
}