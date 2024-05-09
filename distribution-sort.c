#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void distribution_sort(int v[], int n);
int max(int v[], int n);
int min(int v[], int n);
int main(int argc, char **argv) {

    int vetor[5] = {7, 4, 3, 9, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    distribution_sort(vetor,5);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
void distribution_sort(int v[], int n){
    int l=min(v,n);
    int b=max(v,n);
    int z[n];
    int w[b-l+1];
    for (int i = 0; i < b-l+1; i++) {
        w[i]=0;
    }
    for (int i = 0; i <= (n-1); i++) {
        w[v[i]-l]=w[v[i]-l]+1;
    }
    for (int i = 1; i <= (b-l); i++) {
        w[i]=w[i]+w[i-1];
    }
    for (int i = 0; i < (n-1); i++) {
        z[w[v[i]-l]-1]=v[i];
        w[w[i]-l]=w[v[i]-l]-1;
    }
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", z[i]);
    }
}
int max(int v[], int n){
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i]>max) {
            max=v[i];
        }
        
    }
    return max;
}
int min(int v[], int n){
    int min = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i]<min) {
            min=v[i];
        }
    }
    return min;
}