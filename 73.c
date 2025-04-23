#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

const char *so[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
const char *hang[] = {"", "nghin", "trieu", "ty"};

int docNhomBaChuSo(int n, char *buffer, size_t buffer_size) {
    if (n < 0 || n > 999) {
        snprintf(buffer, buffer_size, "So khong hop le (0-999)");
        return -1;
    }
    if (n == 0) {
        buffer[0] = '\0';
        return 0;
    }

    int tram = n / 100;
    int chuc = (n % 100) / 10;
    int donvi = n % 10;
    char temp_buffer[200] = "";
    int len = 0;

    if (tram > 0) {
        len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, "%s tram", so[tram]);
    }

    if (chuc == 0) {
        if (donvi > 0 && tram > 0) {
             len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " linh %s", so[donvi]);
        } else if (donvi > 0 && tram == 0) {
             len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, "%s", so[donvi]);
        }
    } else if (chuc == 1) { 
        len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, "%s muoi", (tram > 0 && len > 0) ? "" : ""); 
         if (tram > 0 && len > 0 && temp_buffer[len-1] != ' ') len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " ");

         len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, "muoi");


        if (donvi == 5) {
            len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " lam");
        } else if (donvi != 0) {
            len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " %s", so[donvi]);
        }
    } else { 
        if (tram > 0 && len > 0) {
             len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " ");
        }
        len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, "%s muoi", so[chuc]);

        if (donvi == 1 && chuc > 1) { 
            len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " mot");
        } else if (donvi == 4 && chuc > 1) { 
            len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " tu");
        } else if (donvi == 5 && chuc > 1) {
             len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " lam");
        } else if (donvi != 0) { 
             len += snprintf(temp_buffer + len, sizeof(temp_buffer) - len, " %s", so[donvi]);
        }
    }

    int start_index = 0;
    while (temp_buffer[start_index] == ' ') {
        start_index++;
    }

    snprintf(buffer, buffer_size, "%s", temp_buffer + start_index);

    return 0;
}

void docSoNguyen(long long num, char *result_buffer, size_t buffer_size) {
    if (num == 0) {
        snprintf(result_buffer, buffer_size, "khong");
        return;
    }

    result_buffer[0] = '\0';
    int len = 0;

    if (num < 0) {
        len += snprintf(result_buffer + len, buffer_size - len, "am ");
        num = -num;
    }

    int groups[4];
    int group_count = 0;

    while (num > 0) {
        groups[group_count++] = num % 1000;
        num /= 1000;
        if (group_count >= 4) break;
    }

    if (group_count == 0 && len > 0) {
    }


    char temp_group_str[200];
    int first_group_read = 0;

    for (int i = group_count - 1; i >= 0; i--) {
        if (groups[i] > 0) {
            if (first_group_read && len > 0 && result_buffer[len-1] != ' ') {
                 len += snprintf(result_buffer + len, buffer_size - len, " ");
            }

            docNhomBaChuSo(groups[i], temp_group_str, sizeof(temp_group_str));
            len += snprintf(result_buffer + len, buffer_size - len, "%s", temp_group_str);
            first_group_read = 1;

            if (i > 0) {
                len += snprintf(result_buffer + len, buffer_size - len, " %s", hang[i]);
            }
        } 
            else {
        }
    }

    if (len > 0 && result_buffer[len - 1] == ' ') {
        result_buffer[len - 1] = '\0';
    }
}

int main() {
    long long n;
    char cach_doc[1000];

    printf("Nhap mot so nguyen: ");
    if (scanf("%lld", &n) != 1) {
         printf("Nhap khong hop le.\n");
         return 1;
    }


    docSoNguyen(n, cach_doc, sizeof(cach_doc));

    printf("Cach doc cua %lld la: %s\n", n, cach_doc);

    return 0;
}