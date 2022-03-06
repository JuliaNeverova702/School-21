#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N;
    scanf("%d%d", &M, &N);
    
    int** pointer_array = malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++)
        pointer_array[i] = malloc(N * sizeof(int));
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &pointer_array[i][j]);
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", pointer_array[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < N; i++) {
        free(pointer_array[i]);
    }
    
    free(pointer_array);
    
    return 0;
}
