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
    int tamMin =100; /*tamanho do menor vetor*/
    int tamMax=10000; /*tamanho do maior vetor*/
    int increment=100; /*vai subindo o tamanho dos arrays*/
    int inter=100; /*quant de iterações*/
    struct timespec a, b;
    unsigned int total;
    FILE *file = fopen("insert_bc_time.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.");
        return 1;
    }
    fprintf(file, "# TamanhoVetor TempoMedio\n");
    for(int dataSize=tamMin; dataSize<=tamMax;dataSize+=increment){
        int *array = (int *)malloc(dataSize * sizeof(int));
        double average_time = 0.0;
        
        for (int i = 0; i < inter; i++) {
            // Inicializa o vetor com valores ordenados de 0 ao tamanho do vetor 
            for (int j = 0; j < dataSize; j++) {
                array[j] = j+1;
            }
            // Executa o algoritmo e mede o tempo
            clock_gettime(CLOCK_MONOTONIC, &b);
            insert_sort(array, dataSize);
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
    printf("Dados salvos no arquivo 'insert_bc_time.txt'.\n");
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