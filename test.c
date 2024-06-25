#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void merge_sort(int v[], int s, int e);
void merge(int v[], int s, int m, int e);
int bsea(int v[], int s, int e, int k);
void merge_sort(int v[], int s,int e){
    if (s<e) {
        int m=(s+e)/2;
        merge_sort(v,s,m);
        merge_sort(v,m+1,e);
        merge(v,s,m,e);
    }
}
void trocar(int vetor[], int pos1, int pos2) {
    int temp = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = temp;
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
int bsea(int v[], int s, int e, int k){
    if (s<e){
        int m =(s+e)/2;
        if (k==v[m]){
            return m;
        }
        if (k<v[m]){
            return bsea(v,s,m-1,k);
        }
        return bsea(v,m+1,e,k);
    }
    return 0;
}
int main(int argc, char **argv) {

    int *array = (int *)malloc(13 * sizeof(int));
    int *array2 = (int *)malloc(13 * sizeof(int));
            for (int j = 0; j < 13; j++) {
                array[j] = rand() % 10;
                array2[j] = array[j];
            }
            merge_sort(array2,0,12);
            int m=(13/2);
            int md=array2[m];
            int p = bsea(array,0,12,md);
            trocar(array,p,(13-1));
    printf("[");
    for (int i = 0; i < 13; i++) {
        printf("%d", array[i]);
        if (i < 13 - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}