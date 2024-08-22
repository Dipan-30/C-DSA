#include <stdio.h>
#include <math.h>

struct Term {
    int coeff;
    int exp;
};

int evaluatePolynomial(struct Term poly[], int n, int x) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += poly[i].coeff * pow(x, poly[i].exp);
    }
    return result;
}

int main() {
    struct Term poly[] = {{5, 3}, {4, 2}, {2, 0}};
    int n = sizeof(poly) / sizeof(poly[0]);
    
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = evaluatePolynomial(poly, n, x);
    
    printf("The result of the polynomial evaluation is: %d\n", result);

    return 0;
}
