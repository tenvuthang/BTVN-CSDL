#include <stdio.h>
#include <string.h>

#define MAX_HS 50
#define MAX_NGANH 5

typedef struct {
    char tenNganh[50];
    float diemChuan;
} Nganh;

typedef struct {
    char maHS[20];
    char tenHS[50];
    float diemToan, diemVan, diemAnh;
    char tenNganhDK[50];
    float diemXetTuyen;
} HocSinh;

int main() {
    int n, m, i, j;
    Nganh dsNganh[MAX_NGANH];
    HocSinh dsHS[MAX_HS];

    printf("Nhap so nganh: ");
    scanf("%d", &m);
    getchar();
    for (i = 0; i < m; i++) {
        printf("Nhap ten nganh thu %d: ", i + 1);
        fgets(dsNganh[i].tenNganh, sizeof(dsNganh[i].tenNganh), stdin);
        dsNganh[i].tenNganh[strcspn(dsNganh[i].tenNganh, "\n")] = 0;
        printf("Nhap diem chuan: ");
        scanf("%f", &dsNganh[i].diemChuan);
        getchar();
    }

    printf("Nhap so hoc sinh: ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        printf("\nNhap thong tin hoc sinh thu %d:\n", i + 1);
        printf("Ma hoc sinh: ");
        fgets(dsHS[i].maHS, sizeof(dsHS[i].maHS), stdin);
        dsHS[i].maHS[strcspn(dsHS[i].maHS, "\n")] = 0;
        printf("Ten hoc sinh: ");
        fgets(dsHS[i].tenHS, sizeof(dsHS[i].tenHS), stdin);
        dsHS[i].tenHS[strcspn(dsHS[i].tenHS, "\n")] = 0;
        printf("Diem Toan: ");
        scanf("%f", &dsHS[i].diemToan);
        printf("Diem Van: ");
        scanf("%f", &dsHS[i].diemVan);
        printf("Diem Anh: ");
        scanf("%f", &dsHS[i].diemAnh);
        getchar();
        printf("Ten nganh dang ky: ");
        fgets(dsHS[i].tenNganhDK, sizeof(dsHS[i].tenNganhDK), stdin);
        dsHS[i].tenNganhDK[strcspn(dsHS[i].tenNganhDK, "\n")] = 0;
        dsHS[i].diemXetTuyen = dsHS[i].diemToan + dsHS[i].diemVan + dsHS[i].diemAnh;
    }

    printf("\n%-10s %-20s %-8s %-8s %-8s %-20s %-10s\n", "MaHS", "TenHS", "Toan", "Van", "Anh", "NganhDK", "DiemXT");
    for (i = 0; i < n; i++) {
        printf("%-10s %-20s %-8.2f %-8.2f %-8.2f %-20s %-10.2f\n",
            dsHS[i].maHS, dsHS[i].tenHS, dsHS[i].diemToan, dsHS[i].diemVan, dsHS[i].diemAnh,
            dsHS[i].tenNganhDK, dsHS[i].diemXetTuyen);
    }

    return 0;
}