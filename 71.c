#include <stdio.h>

int tinhGiaiThua(int n) {
    if (n < 0) {
        printf("Khong the tinh giai thua cho so am.\n");
        return -1; 
    }
    if (n == 0) {
        return 1;
    }
    int giai_thua = 1;
    for (int i = 1; i <= n; ++i) {
        giai_thua *= i;
    }
    return giai_thua;
}

double tinhTongNghichDao(int n) {
    if (n <= 0) {
        printf("n phai lon hon 0 de tinh tong nghich dao.\n");
        return 0.0; 
    }
    double tong = 0.0;
    for (int i = 1; i <= n; ++i) {
        tong += 1.0 / i;
    }
    return tong;
}

int tinhTongBinhPhuong(int n) {
     if (n <= 0) {
        printf("n phai lon hon 0 de tinh tong binh phuong.\n");
        return 0; 
    }
    int tong = 0;
    for (int i = 1; i <= n; ++i) {
        tong += (int)i * i;
    }
    return tong;
}

int main() {
    int n;

    printf("Nhap mot so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap mot so nguyen lon hon 0.\n");
        return 1;
    }

    int gt = tinhGiaiThua(n);
    if (gt != -1) {
         printf("Giai thua cua %d la: %lld\n", n, gt);
    }

    double tnd = tinhTongNghichDao(n);
    printf("Tong nghich dao tu 1 den %d la: %lf\n", n, tnd);

    int tbp = tinhTongBinhPhuong(n);
    printf("Tong binh phuong tu 1 den %d la: %lld\n", n, tbp);

    return 0; 
}