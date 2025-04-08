#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool kiemTraNhap(int *n) {
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return false;
    }
    return (sscanf(buffer, "%d", n) == 1);
}

int phanHoach(int arr[], int low, int high, bool tangdan) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if ((tangdan && arr[j] < pivot) || (!tangdan && arr[j] > pivot)) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, bool tangDan) {
    if (low < high) {
        int pi = phanHoach(arr, low, high, tangDan);
        quickSort(arr, low, pi - 1, tangDan);
        quickSort(arr, pi + 1, high, tangDan);
    }
}

int main() {
    int n;
    char sapXep;
    
    do {
        printf("Nhap so luong phan tu (n > 2): ");
        if (!kiemTraNhap(&n)) {
            printf("Loi,vui long nhap lai\n");
            while (getchar() != '\n');
            continue;
        }
        if (n <= 2) {
            printf("Loi, vui lap so lon hon 2\n");
        }
    } while (n <= 2);
    
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }
    
    printf("Nhap %d so:\n", n);
    for (int i = 0; i < n; i++) {
        do {
            printf("Nhap so thu %d: ", i + 1);
            if (!kiemTraNhap(&arr[i])) {
                printf("Loi, vui long nhap lai\n");
                while (getchar() != '\n'); 
            } else {
                break;
            }
        } while (true);
    }
    
    do {
        printf("Sap xep tang dan (T) hay giam dan (G)? ");
        scanf(" %c", &sapXep);
        sapXep = toupper(sapXep);
    } while (sapXep != 'T' && sapXep != 'G');
    
    quickSort(arr, 0, n - 1, sapXep == 'T');
    
    printf("\nDay so sau khi sap xep %s:\n", (sapXep == 'T') ? "tang dan" : "giam dan");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}