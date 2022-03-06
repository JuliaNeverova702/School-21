#include <stdlib.h>
#include <stdio.h>

int input_value (int *N, int *M) {
    int f = 0;
    if (scanf("%d%d", N, M) != 2 && *N > 0 && *M > 0)
        f = 1;
    return f;
}

void input (int **A, int *N, int *M) {
    A = (int**) malloc(*N * sizeof(int*));
    for (int i = 0; i < *N; i++) {
        A[i] = (int*) malloc(*M * sizeof(int));
    }
    for (int i = 0; i < *N; i++) {
        for (int j = 0; j < *M; j++) {
            scanf("%d", &A[i][j]);
        }
     }
}

void output(int **A, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", A[i][j]);
        }
     }
}

void free_the_memory(int **A, int N) {
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}

int main() {
    int M, N;
    int **A = NULL;
    if (input_value(&N, &M) == 0) {
        input (A, &N, &M);
        output(A, N, M);
    }
    
    
    free_the_memory(A, N);
    return 0;
}
