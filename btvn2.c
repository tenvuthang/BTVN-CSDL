#include <stdio.h>

int main() {
    printf("Nhap diem: ");
    float diem;
    if (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
        printf("Diem khong hop le. Vui long nhap lai.");
        return 1;
    }
    if (diem >= 9.0) {
        printf("Xep loai: Xuat sac\n");
    } else if (diem >= 8.0) {
        printf("Xep loai: Gioi\n");
    } else if (diem >= 7.0) {
        printf("Xep loai: Kha\n");
    } else if (diem >= 5.0) {
        printf("Xep loai: Trung binh\n");
    } else {
        printf("Xep loai: Yeu\n");
    }
    return 0;
}