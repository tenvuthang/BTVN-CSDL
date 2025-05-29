#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Sinh_vien {
    char hoVaTen[30];
    int namSinh;
    float diemCC, diemKT, diemThi, diemHP;
};

int main()
{
    int n;
    struct Sinh_vien ds[MAX];

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    if (n > MAX) {
        printf("So luong sinh vien vuot qua gioi han (%d)!\n", MAX);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nNhap lieu cho sinh vien thu %d:\n", i + 1);
        printf("Ho va ten: ");
        fgets(ds[i].hoVaTen, sizeof(ds[i].hoVaTen), stdin);
        printf("Nam sinh: ");
        scanf("%d", &ds[i].namSinh);
        printf("Diem CC: ");
        scanf("%f", &ds[i].diemCC);
        printf("Diem KT: ");
        scanf("%f", &ds[i].diemKT);
        printf("Diem Thi: ");
        scanf("%f", &ds[i].diemThi);
        ds[i].diemHP = ds[i].diemCC * 0.1 + ds[i].diemKT * 0.4 + ds[i].diemThi * 0.5;
        getchar();
    }

    printf("\nThong tin cac sinh vien\n");
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ho va ten: %s", ds[i].hoVaTen);
        printf("Nam sinh: %d\n", ds[i].namSinh);
        printf("Diem CC: %.2f\n", ds[i].diemCC);
        printf("Diem KT: %.2f\n", ds[i].diemKT);
        printf("Diem Thi: %.2f\n", ds[i].diemThi);
        printf("Diem HP: %.2f\n", ds[i].diemHP);
    }

    return 0;
}

