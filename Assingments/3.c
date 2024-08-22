#include <stdio.h>

struct Term {
    int coeff;
    int exp;
};

void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int *resSize) {
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        if (poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exp < poly2[j].exp) {
            result[k++] = poly2[j++];
        } else {
            result[k].exp = poly1[i].exp;
            result[k++].coeff = poly1[i++].coeff + poly2[j++].coeff;
        }
    }

    while (i < n1) {
        result[k++] = poly1[i++];
    }

    while (j < n2) {
        result[k++] = poly2[j++];
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
    struct Term poly1[] = {{5, 3}, {4, 2}, {2, 0}};
    struct Term poly2[] = {{3, 3}, {1, 1}, {7, 0}};
    
    int n1 = sizeof(poly1) / sizeof(poly1[0]);
    int n2 = sizeof(poly2) / sizeof(poly2[0]);
    
    struct Term result[10];
    int resSize;

    addPolynomials(poly1, n1, poly2, n2, result, &resSize);
    
    printf("Resultant Polynomial: ");
    printPolynomial(result, resSize);

    return 0;
}
