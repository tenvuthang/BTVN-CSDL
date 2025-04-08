#include <stdio.h>

int main(){
    printf("Nhap ho thang: ");
    int thang;
    
    if (scanf("%d", &thang) != 1 || thang < 1 || thang > 12) {
        printf("Thang khong hop le. Vui long nhap lai.");
        return 1;
    }
    if (thang ==2)
        printf("Thang 2 co 28 hoac 29 ngay");
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
        printf("Thang %d co 30 ngay", thang);
    else
        printf("Thang %d co 31 ngay", thang);
    return 0;
}
