#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

void multiplyPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int *resSize) {
    int k = 0;
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int coeff = poly1[i].coeff * poly2[j].coeff;
            int exp = poly1[i].exp + poly2[j].exp;

            int found = 0;

            for (int l = 0; l < k; l++) {
                if (result[l].exp == exp) {
                    result[l].coeff += coeff;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                result[k].coeff = coeff;
                result[k].exp = exp;
                k++;
            }
        }
    }

    *resSize = k;
}

void printPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i < n - 1)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term poly1[] = {{5, 2}, {4, 1}, {2, 0}};
    struct Term poly2[] = {{3, 1}, {1, 0}};
    
    int n1 = sizeof(poly1) / sizeof(poly1[0]);
    int n2 = sizeof(poly2) / sizeof(poly2[0]);
    
    struct Term result[20];
    int resSize;

    multiplyPolynomials(poly1, n1, poly2, n2, result, &resSize);
    
    printf("Resultant Polynomial after Multiplication: ");
    printPolynomial(result, resSize);

    return 0;
}
