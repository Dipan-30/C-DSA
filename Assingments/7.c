#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

void addSparseMatrices(struct Element mat1[], int n1, struct Element mat2[], int n2, struct Element result[], int *resSize) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k++] = mat1[i++];
        } else if (mat1[i].row > mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col > mat2[j].col)) {
            result[k++] = mat2[j++];
        } else {
            result[k] = mat1[i];
            result[k++].value = mat1[i++].value + mat2[j++].value;
        }
    }

    while (i < n1) {
        result[k++] = mat1[i++];
    }

    while (j < n2) {
        result[k++] = mat2[j++];
    }

    *resSize = k;
}

void printSparseMatrix(struct Element mat[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) = %d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}

int main() {
    struct Element mat1[] = {{0, 0, 5}, {0, 2, 8}, {1, 1, 3}};
    struct Element mat2[] = {{0, 1, 7}, {0, 2, 6}, {1, 1, 9}, {2, 0, 4}};
    
    int n1 = sizeof(mat1) / sizeof(mat1[0]);
    int n2 = sizeof(mat2) / sizeof(mat2[0]);
    
    struct Element result[10];
    int resSize;

    addSparseMatrices(mat1, n1, mat2, n2, result, &resSize);

    printf("Resultant Sparse Matrix after Addition:\n");
    printSparseMatrix(result, resSize);

    return 0;
}
