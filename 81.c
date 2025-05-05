#include <stdio.h>
#include <string.h>

void layTen(char hoTen[], char ten[]) {
    int length = strlen(hoTen);
    int i;

    for (i = length - 1; i >= 0; i--) {
        if (hoTen[i] == ' ') {
            break;
        }
    }

    strcpy(ten, &hoTen[i + 1]);
}

int main() {
    char hoTen[100], ten[50];

    printf("Nhap ho va ten: ");
    scanf(" %[^\n]", hoTen);

    hoTen[strcspn(hoTen, "\n")] = 0;

    layTen(hoTen, ten);

    printf("Ten la: %s\n", ten);

    return 0;
}
