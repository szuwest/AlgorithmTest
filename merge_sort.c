#include "merge_sort.h"
#include <stdlib.h>

void _sorted_merge(int a[], int start, int mid, int end) {
    int len_l = mid - start + 1;
    int len_r = end - mid;
    int *arr_l = (int *)malloc(sizeof(int)*len_l);
    int *arr_r = (int *)malloc(sizeof(int)*len_r);

    for (int i=0; i<len_l; i++) {
        arr_l[i] = a[start+i];
    }
    for (int i=0; i<len_r; i++) {
        arr_r[i] = a[mid+i+1];
    }

    int i = 0;
    int j = 0;
    int k = start;
    while (i < len_l && j < len_r) {
        if (arr_l[i] <= arr_r[j]) {
            a[k++] = arr_l[i++];
        } else {
            a[k++] = arr_r[j++];
        }
    }
    while (i < len_l) a[k++] = arr_l[i++];
    while (j < len_r) a[k++] = arr_r[j++];

    free(arr_l);
    free(arr_r);
}

void _recursive_merge_sort(int a[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        _recursive_merge_sort(a, start, mid);
        _recursive_merge_sort(a, mid+1, end);
        _sorted_merge(a, start, mid, end);
    }
}

void recursive_merge_sort(int a[], int n) {
    if (a == 0 || n <= 1) return;
    _recursive_merge_sort(a, 0, n-1);
}

void iteractive_merge_sort(int a[], int n) {
    if (a == 0 || n <= 1) return;

    int step = 1;
    while (step < n) {
        int start = 0, mid = 0, end = 0;
        while (start < n-1) {
            mid = start + step - 1;
            end = mid + step;
            if (end > n-1) end = n-1;
            _sorted_merge(a, start, mid, end);
            start += 2*step;
        }

        step = 2*step;
    }
}

void _merge_array(int a[], int b[], int n, int step) {
    int k = 0;
    int start1 = 0;
    int end1, start2, end2;
    
    while (k < n) {
        end1 = start1 + step;
        start2 = end1;
        end2 = start2 + step;
        if (end2 > n) end2 = n;
        while (start1 < end1 && start2 < end2) {
            if (a[start1] <= a[start2]) {
                b[k++] = a[start1++];
            } else {
                b[k++] = a[start2++];
            }
        }
        while (start1 < end1) b[k++] = a[start1++];
        while (start2 < end2) b[k++] = a[start2++];

        start1 = end2;
    }
}

void iteractive_merge_sort2(int a[], int n) {
    if (a == 0 || n <= 1) return;

    int *b = (int *)malloc(sizeof(int)*n);
    int flag = 0;
    for (int i = 1; i<n; i=i*2) {
        if (flag == 0) {
            _merge_array(a, b, n, i);
            flag = 1;
        } else {
            _merge_array(b, a, n, i);
            flag = 0;
        }
    }

    if (flag == 1) {
        for (int i=0; i<n; i++) a[i] = b[i];
    }

    free(b);
}