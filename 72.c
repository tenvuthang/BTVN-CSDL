#include <stdio.h>
#include <stdlib.h> 

int ucln(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a == 0) return b;
    if (b == 0) return a;

    int temp;
    while (b != 0) {
        temp = b;
        b = a % b; 
        a = temp;  
    }
    return a;
}

int bcnn(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }

    int abs_a = abs(a);
    int abs_b = abs(b);

    int gcd = ucln(abs_a, abs_b);

    return (abs_a / gcd) * abs_b;
}

int main() {
    int num1, num2;

    printf("Nhap so nguyen thu nhat: ");
    scanf("%d", &num1);

    printf("Nhap so nguyen thu hai: ");
    scanf("%d", &num2);

    int ucln_result = ucln(num1, num2);
    int bcnn_result = bcnn(num1, num2);

    printf("Uoc Chung Lon Nhat (UCLN) cua %d va %d la: %d\n", num1, num2, ucln_result);
    printf("Boi Chung Nho Nhat (BCNN) cua %d va %d la: %d\n", num1, num2, bcnn_result);

    return 0; 
}