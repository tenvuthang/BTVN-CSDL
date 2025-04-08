#include <stdio.h>
#include <stdlib.h>

int phanHoach(int arr[], int low, int high, int tangDan) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if ((tangDan && arr[j] < pivot) || (!tangDan && arr[j] > pivot)) {
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

void quickSort(int arr[], int low, int high, int tangDan) {
    if (low < high) {
        int pi = phanHoach(arr, low, high, tangDan);
        quickSort(arr, low, pi - 1, tangDan);
        quickSort(arr, pi + 1, high, tangDan);
    }
}

int main() {
    int n;
    int sapXep;
    
    printf("Nhap so luong phan tu (n > 2): ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Nhap %d so:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Sap xep tang dan (1) hay giam dan (0)? ");
    scanf("%d", &sapXep);
    
    quickSort(arr, 0, n - 1, sapXep);
    
    printf("\nDay so sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}