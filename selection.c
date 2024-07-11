#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void selection_sort(int v[], int n);
void trocar(int vetor[], int pos1, int pos2);
int main(int argc, char **argv) {
    int array[6] = {7, 4, 3, 9, 5,3};
    selection_sort(array, 6);
    for(int i = 0; i <6; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
void selection_sort(int v[], int n) {
    for (int i = 0; i <(n-1); i++) {
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