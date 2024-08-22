#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int A[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int B[ROWS * COLS];
    
    // Mapping 2D array to 1D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int k = i * COLS + j;
            B[k] = A[i][j];
        }
    }
    
    // Printing the 1D array
    printf("Contents of the 1D array:\n");
    for (int i = 0; i < ROWS * COLS; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
    
    return 0;
}