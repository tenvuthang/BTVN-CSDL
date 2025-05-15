#include <stdio.h>
#include <string.h>

int main() {
    int i, n;
    char hoten[60][30]; 
    printf("So luong sinh vien trong lop: ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        printf("Ho ten sinh vien thu %d: ", i + 1);
        fgets(hoten[i], 30, stdin); 
        size_t len = strlen(hoten[i]);
        if (len > 0 && hoten[i][len - 1] == '\n') {
            hoten[i][len - 1] = '\0';
        }
    }

    for (i = 0; i < n; i++) {
        printf("\nHo ten sinh vien thu %d: %s", i + 1, hoten[i]);
    }

    return 0;
}