#include <stdio.h>
int fibo (int i)
{
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fibo(i - 1) + fibo(i - 2);
}
int main()
{
    int i, j, sum = 0;
    printf("Nhap so: ");
    scanf("%d", &i);
    printf("Cac so Fibonacci tu 1 den %d la:\n", i);
    for (j = 1; j <= i; j++) {
        int fib = fibo(j);
        printf("%d ", fib);
        sum += fib; 
    }
    printf("\nTong cac so Fibonacci: %d\n", sum); 
    return 0;
}
