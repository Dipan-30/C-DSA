#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

void countNonZeroInRows(struct Element mat[], int n, int numRows) {
    int count[numRows];

    // Initialize count array with zeros
    for (int i = 0; i < numRows; i++) {
        count[i] = 0;
    }

    // Count the number of non-zero elements in each row
    for (int i = 0; i < n; i++) {
        count[mat[i].row]++;
    }

    // Print the count of non-zero elements in each row
    for (int i = 0; i < numRows; i++) {
        printf("Row %d has %d non-zero elements\n", i, count[i]);
    }
}

int main() {
    struct Element mat[] = {
        {0, 0, 5},
        {0, 2, 8},
        {1, 1, 3},
        {2, 0, 7},
        {2, 3, 6},
        {3, 1, 4}
    };
    
    int n = sizeof(mat) / sizeof(mat[0]);  // Number of non-zero elements
    int numRows = 4;  // Number of rows in the sparse matrix

    countNonZeroInRows(mat, n, numRows);

    return 0;
}
