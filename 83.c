#include <stdio.h>
void chuyen(int sodia, int cotdau, int cotdich, int cotphu)
{
    if (sodia == 1) {
        printf("Chuyen dia tu cot %d sang cot %d\n", cotdau, cotdich);
        return;
    }
    chuyen(sodia - 1, cotdau, cotphu, cotdich);
    printf("Chuyen dia tu cot %d sang cot %d\n", cotdau, cotdich);
    chuyen(sodia - 1, cotphu, cotdich, cotdau);
}
int main()
{
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);
    chuyen(n, 1, 3, 2);
    return 0;
}