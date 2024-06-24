#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void merge_sort(int v[], int s, int e);
void merge(int v[], int s, int m, int e);

int main(int argc, char **argv) {
    int tamMin =100; /*tamanho do menor vetor*/
    int tamMax=10000; /*tamanho do maior vetor*/
    int increment=100; /*vai subindo o tamanho dos arrays*/
    int inter=100; /*quant de iterações*/
    struct timespec a, b;
    unsigned int total;
    FILE *file = fopen("merge_time.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.");
        return 1;
    }
    fprintf(file, "# TamanhoVetor TempoMedio\n");
    for(int dataSize=tamMin; dataSize<=tamMax;dataSize+=increment){
        int *array = (int *)malloc(dataSize * sizeof(int));
        double average_time = 0.0;
        
        for (int i = 0; i < inter; i++) {
            // Inicializa o vetor com valores aleatórios
            for (int j = 0; j < dataSize; j++) {
                array[j] = rand() % 1000;
            }
            // Executa o algoritmo e mede o tempo
            clock_gettime(CLOCK_MONOTONIC, &b);
            merge_sort(array,0,(dataSize-1));
            clock_gettime(CLOCK_MONOTONIC, &a);
            total= (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
            double total_s=total/1e9;
            average_time += total_s;
        }
        average_time /=inter; // ao fim do for de cada vetor de tam ele devide o tempo de execulção de todos e divide pela interação
        fprintf(file, "%d %lf\n", dataSize, average_time);
        free(array);
    }
    fclose(file);
    printf("Dados salvos no arquivo 'merge_time.txt'.\n");
    return 0;
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