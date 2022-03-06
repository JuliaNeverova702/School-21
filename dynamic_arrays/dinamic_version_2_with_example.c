#include <stdio.h>
#include <stdlib.h>

int input_value(int *N, int *M);
int input_matrix(int N, int M);

int main() {
    int M, N;
    if (input_value(&N, &M)) {
       if (input_matrix(N, M)) {
           create_matrix(N, M);
        }
    }
    
    return 0;
}

void create_matrix(int N, int M) {
    int **pointer_array = (int*) malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        array[i] = malloc(N * sizeof(int));
    
    input_matrix(pointer_array, &N, &M);
    output_matrix();
    
    for (int i = 0; i < N; i++) {
        free(pointer_array[i]);
    }
    
    free(pointer_array);
}

int input_value(int *N, int *M) {
    int flag = 0;
    if (!scanf("%d%d", M, N) && M > 0 && N > 0)
        else {
            flag = 1;
            printf ("n/a");
        }
    return flag;
}

int input_matrix(int **array, int *N, *M) {
    int flag = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", array[i][j]) != 1) {
                flag = 1;
                printf ("n/a");
                break;
            }
        }
    }
    return flag;
}


void output_matrix(int **array, int N, M) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
