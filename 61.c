#include <stdio.h>
#include <ctype.h> 

int main() {
    char ch;

    printf("Nhap mot ki tu: ");
    scanf(" %c", &ch); 

    switch(ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("'%c' la nguyen am.\n", ch);
            break;
        default:
            if (ch >= 'a' && ch <= 'z') {
                printf("'%c' la phu am.\n", ch);
            } else {
                printf("'%c' khong phai chu cai tieng Anh.\n", ch);
            }
    }

    return 0;
}