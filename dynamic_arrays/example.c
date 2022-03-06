#include <stdio.h>
#include <stdlib.h>
//vjvh

void create_matrix1(int m, int n);
void create_matrix2(int m, int n);
void create_matrix3(int m, int n);
void create_static_matrix(int m, int n);
void select_mode(int mode, int m, int n);
int output(int m, int n, int **matrix);
int input_matrix(int m, int n, int **matrix);
int input(int *mode, int *m, int *n);

int main() {
    int m, n, mode;
    if (input(&mode, &m, &n)) {
        select_mode(mode, m, n);
    } else {
        printf("n/a");
    }
    return 0;
}

void create_matrix1(int m, int n) {
    int **pointer_array = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        pointer_array[i] = malloc(m * sizeof(int *));
    }

    input_matrix(m, n, pointer_array);
    output(m, n, pointer_array);

    for (int i = 0; i < m; i++) {
        free(pointer_array[i]);
    }

    free(pointer_array);
}

void create_matrix2(int m, int n) {
    int **pointer_array = malloc(m * sizeof(int *));
    int *values_array = malloc(m * n * sizeof(int));

    for (int i = 0; i < m; i++) {
        pointer_array[i] = values_array + n * i;
    }

    input_matrix(m, n, pointer_array);
    output(m, n, pointer_array);

    free(values_array);
    free(pointer_array);
}

void create_matrix3(int m, int n) {
    int **single_array_matrix = malloc(m * n * sizeof(int *) + m * sizeof(int *));
    int *ptr = (int *)(single_array_matrix + m);
    for (int i = 0; i < m; i++) {
        single_array_matrix[i] = ptr + n * i;
    }
    input_matrix(m, n, single_array_matrix);
    output(m, n, single_array_matrix);
    free(single_array_matrix);
}

int input(int *mode, int *m, int *n) {
    int check = 1;
    if (scanf("%d", mode) != 1 || *mode <= 0 || *mode > 4) {
        check = 0;
    } else {
        if (scanf("%d%d", m, n) != 2 || *n <= 0 || *m <= 0) {
            check = 0;
        }
    }
    return check;
}

int input_matrix(int m, int n, int **matrix) {
    int item = 0;
    int check = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &item) != 1 || item < 0) {
                check = 0;
                break;
            } else {
                matrix[i][j] = item;
            }
        }
    }
    return check;
}

int output(int m, int n, int **matrix) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\b\n");
    }
    return 0;
}

void select_mode(int mode, int m, int n) {
    switch (mode) {
        case 1:
            create_matrix1(m, n);
            break;

        case 2:
            create_matrix2(m, n);
            break;

        case 3:
            create_matrix3(m, n);
            break;

        case 4:
            create_static_matrix(m, n);
            break;
    }
}

void create_static_matrix(int m, int n) {
    int static_matrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &static_matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", static_matrix[i][j]);
        }
        printf("\b\n");
    }
}
