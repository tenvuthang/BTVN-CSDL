#include <stdio.h>

int main() {
    int n;
    int i;
    int snt = 1;

    printf("Nhap vao so N: ");
    scanf("%d", &n);

    if (n <= 1) {
        snt = 0; 
    } 
    else {
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                snt = 0; 
                break;        
            }
        }
    }

    if (snt == 1) {
        printf("%d la so nguyen to\n", n);
    } 
    else {
        printf("%d khong phai la so nguyen to\n", n);
    }

    return 0;
}
