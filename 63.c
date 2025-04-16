#include <stdio.h>

int main() {
    int n, choice;
    int i, j; 

    printf("Nhap so hang n: ");
    scanf("%d", &n);

    printf("\n--- MENU ---\n");
    printf("1. Tam giac sao can\n");
    printf("2. Tam giac sao vuong lech trai\n");
    printf("3. Tam giac sao vuong lech phai\n");
    printf("4. Tam giac sao can nguoc\n");
    printf("Nhap lua chon cua ban (1-4): ");
    scanf("%d", &choice);
    printf("\n"); 

    switch (choice) {
        case 1: 
            printf("Tam giac sao can:\n");
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n - i; j++) {
                    printf(" ");
                }
                for (j = 1; j <= 2 * i - 1; j++) {
                    printf("*");
                }
                printf("\n"); 
            }
            break;

        case 2:
            printf("Tam giac sao vuong lech trai:\n");
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n"); 
            }
            break;

        case 3: 
            printf("Tam giac sao vuong lech phai:\n");
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n - i; j++) {
                    printf(" ");
                }
                for (j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 4:
             printf("Tam giac sao can nguoc:\n");
            for (i = n; i >= 1; i--) { 
                for (j = 1; j <= n - i; j++) {
                    printf(" ");
                }
                for (j = 1; j <= 2 * i - 1; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        default: 
            printf("Lua chon khong hop le.\n");
            break;
    }

    return 0;
}
