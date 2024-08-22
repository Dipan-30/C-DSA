#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseStr(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void addLargeNumbers(char num1[], char num2[], char result[]) {
    reverseStr(num1);
    reverseStr(num2);
    
    int carry = 0, i = 0;
    int len1 = strlen(num1), len2 = strlen(num2);
    int max_len = len1 > len2 ? len1 : len2;

    for (i = 0; i < max_len; i++) {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (i < len2) ? num2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) {
        result[i++] = carry + '0';
    }

    result[i] = '\0';
    reverseStr(result);
}

int main() {
    char num1[1000], num2[1000], result[1001];

    printf("Enter the first large number: ");
    scanf("%s", num1);

    printf("Enter the second large number: ");
    scanf("%s", num2);

    addLargeNumbers(num1, num2, result);

    printf("The sum is: %s\n", result);

    return 0;
}
