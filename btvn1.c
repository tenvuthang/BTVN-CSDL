#include <stdio.h>
#include <string.h>
#define luongcoban 2140000


int main() {
    char hoten[50];
    float hesoluong, tienthuong, tamung, thucnhan;
    
    printf("Nhap ho ten nhan vien: ");
    scanf(" %[^\n]", hoten);

    printf("Nhap he so luong: ");
    scanf("%f", &hesoluong);

    printf("Nhap tien thuong: ");
    scanf("%f", &tienthuong);

    printf("Nhap tam ung: ");
    scanf("%f", &tamung);

    thucnhan = luongcoban * hesoluong + tienthuong - tamung;

    printf("\n|%-20s|%-15s|%-15s|%-15s|%-15s|", "Ho ten", "He so luong", "Tien thuong", "Tam ung", "Thuc nhan");
    printf("\n|%-20s|%-15.2lf|%-15.2lf|%-15.2lf|%-15.2lf|", hoten, hesoluong, tienthuong, tamung, thucnhan);
    
    return 0;
}