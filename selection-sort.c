#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void selection_sort(int v[], int n);
void trocar(int vetor[], int pos1, int pos2);
int main(int argc, char **argv) {

    int vetor[5] = {7, 4, 3, 9, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    selection_sort(vetor,5);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
void selection_sort(int v[], int n) {
    for (int i = 0; i <= (n); i++) {
        int min=i;
        for (int j = (i+1); j < n; j++) {
            if (v[j]<v[min]) {
                min=j;
            }
        }
        trocar(v,i,min);
    }
}
void trocar(int vetor[], int pos1, int pos2) {
    int temp = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = temp;
}