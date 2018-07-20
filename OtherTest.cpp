#include <stdlib.h>

void sorted_array_merge(int a[], int start, int mid, int end) {
    int lenL = mid - start + 1;
    int lenR = end - mid;
    int *arrL = (int *)malloc(sizeof(int)*lenL);
    int *arrR = (int *)malloc(sizeof(int)*lenR);

    for (int i=0; i<lenL; i++) {
        arrL[i] = a[start+i];
    }
    for (int i=0; i<lenR; i++) {
        arrR[i] = a[mid+1+i];
    }

    int i = 0, j = 0, k = start;
    while (i < lenL && j<lenR) {
        if (arrL[i] <= arrR[j]) {
            a[k++] = arrL[i++];
        } else {
            a[k++] = arrR[j++];
        }
    }

    while (i<lenL) a[k++] = arrL[i++];
    while (j<lenR) a[k++] = arrR[j++];

    free(arrL);
    free(arrR);
}

void _recursive_merge(int a[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        _recursive_merge(a, start, mid);
        _recursive_merge(a, mid+1, end);
        sorted_array_merge(a, start, mid, end);
    }
}

void recursive_merge(int a[], int n) {
    if (a == 0 || n <= 1) return;

    _recursive_merge(a, 0, n-1);
}

void iteractive_merge(int a[], int n) {
    if (a == 0 || n <= 1) return;

    int step = 1;
    while (step < n) {
        int start = 0, mid = 0, end = 0;
        while (start < n-1) {
            mid = start + step - 1;
            end = mid + step;
            if (end > n-1) end = n-1;
            sorted_array_merge(a, start, mid, end);

            start += step*2;
        }
        step = 2*step;
    }
}

void sorted_merge_array(int a[], int b[], int n, int step) {
    int k = 0;
    int start1 = 0, end1 = 0, start2 = 0, end2 = 0;
    while (k < n) {
        end1 = start1 + step;
        start2 = end1;
        end2 = start2 + step;
        if (end2 > n-1) end2 = n-1;
        while (start1 < end1 && start2 < end2) {
            if (a[start1] <= a[start2]) {
                b[k++] = a[start1++];
            } else {
                b[k++] = a[start2++];
            }
        }
        while (start1 < end1) b[k++] = a[start1++];
        while (start2 < end2) b[k++] = a[start2++];

        start1 = start2;
    }
}

void iteractive_merge2(int a[], int n) {
    if (a == 0 || n <= 1) return;

    int *b = (int *)malloc(sizeof(int)*n);
    int flag = 0;
    for (int step=1; step<n; step=2*step) {
        if (flag == 0) {
            sorted_merge_array(a, b, n, step);
            flag = 1;
        } else {
            sorted_merge_array(b, a, n, step);
            flag = 0;
        }
    }

    if (flag == 1) {
        for (int i=0; i<n; i++) a[i] = b[i];
    }

    free(b);
}