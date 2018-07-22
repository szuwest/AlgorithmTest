#include "sort_algorithm.h"
#include <stdlib.h>
#include <stdio.h>

void _mergeSort(int a[], int b[], int n, int step) {
    int start1 = 0;
    int end1, start2, end2;
    int k = 0;
    while(k<n) {
        end1 = start1+step;
        if (end1>n) end1 = n;
        start2 = end1;
        end2 = start2+step;
        if (end2>n) end2 = n;

        while(start1<end1 && start2<end2) {
            if (a[start1] < a[start2]) {
                b[k++] = a[start1++];
            } else {
                b[k++] = a[start2++];
            }
        }
        while (start1<end1)b[k++] = a[start1++];
        while (start2<end2)b[k++] = a[start2++];
        
        start1 = start2;
    }
}

void mergeSort(int a[], int n) {
    if (a == 0 || n == 0) return;
    int* b = (int *)malloc(sizeof(int)*n);

    int flag = 0;
    for(int i=1;i<n;i=i*2) {
        if (flag == 0) {
            _mergeSort(a, b, n, i);
            flag = 1;
        } else {
            _mergeSort(b, a, n, i);
            flag = 0;
        }
    }

    if (flag == 1) {
        for(int i=0;i<n;i++) {
            a[i] = b[i];
        }
    }

    free(b);
}

void sorted_merge(int a[], int start, int mid, int end) {
    int len_l = mid - start + 1;
    int len_r = end - mid;
    int *arr_l = (int *)malloc(sizeof(int)*len_l);

    for (int i=0;i<len_l;i++) {
        arr_l[i] = a[start+i];
    }
    int *arr_r = (int *)malloc(sizeof(int)*len_r);
    for (int j=0;j<len_r;j++) {
        arr_r[j] = a[mid+j+1];
    }
    int i = 0, j = 0;
    int k = start;
    while(i < len_l && j < len_r) {
        if (arr_l[i] <= arr_r[j]) {
            a[k++] = arr_l[i++];
        } else {
            a[k++] = arr_r[j++];
        }
    }
    while(i<len_l) a[k++] = arr_l[i++];
    while(j<len_r) a[k++] = arr_r[j++];

    free(arr_l);
    free(arr_r);
}

void recursive_merge(int a[], int start, int end) {
    if (start >= end) return;
    int mid = start+(end-start)/2;
    recursive_merge(a, start, mid);
    recursive_merge(a, mid+1, end);
    sorted_merge(a, start, mid, end);
}

void recursive_mergeSort(int a[], int n) {
    if (a == 0 || n <= 1) return;

    recursive_merge(a, 0, n-1);
}

void iteractive_mergeSort(int a[], int n) {
    if (a == 0 || n <= 1) return;

    int step = 1;
    while (step < n) {
        int start = 0, mid = 0, end = 0;
        while(start < n-1) {
            mid = start + step - 1;
            end = mid + step;
            if (end > n-1) end = n-1;
            sorted_merge(a, start, mid, end);
            start += 2*step;
        }
        step = step*2;
    }
}

void _buildHeap(int a[], int n, int k) {

    int i = k;
    while(2*i+1<n) {
        int j = 2*i+1;
        if (2*i+2 < n && a[2*i+2] > a[2*i+1]) j = 2*i+2;
        if (a[j] > a[i]) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        i = j;
    }
}

void heapSort(int a[], int n) {
    if (a == 0 || n == 0) return;
    
    for(int i=(n-1)/2; i>=0; i--) {
        _buildHeap(a, n, i);
    }

    for (int i=n-1; i>0; i--) {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        _buildHeap(a, i, 0);
    }
}


// Function to swap numbers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
/* This function takes last element as pivot,
   places the pivot element at its correct
   position in sorted  array, and places
   all smaller (smaller than pivot) to left
   of pivot and all greater elements to 
   right of pivot */
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted, 
l --> Starting index, 
h --> Ending index */
void quickSort2(int A[], int l, int h)
{
    if (l < h)
    {     
        /* Partitioning index */
        int p = partition(A, l, h); 
        quickSort2(A, l, p - 1); 
        quickSort2(A, p + 1, h);
    }
     
}

void _quickSort(int a[], int start, int end) {
    if (start >= end) return;
    int value = a[start];
    int i = start, j = end;
    while (i<j) {
        while(i<j && a[j]>value) j--;
        if (i<j) {
            a[i] = a[j];
            i++;
        }
        while( i<j && a[i] < value) i++;
        if (i < j) {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = value;
    if (i>start) _quickSort(a, start, i-1);
    if (i<end) _quickSort(a, i+1, end);
}

void quickSort(int a[], int n) {
    if (a == 0 || n == 0) return;
    // _quickSort(a, 0, n-1);
    quickSort2(a, 0, n-1);
}


void testSort() {
    int a[] = {2,5,59,32,12,8,32,15,44,82,19,13};
    int len = 12;
    printf("before sort:\n");
    for (int i=0;i<len;i++) {
        printf("%d ", a[i]);
    }
    printf("\nafter sort:\n");
    
    // heapSort(a, len);
    quickSort(a, len);
    // mergeSort(a,len);
    // recursive_mergeSort(a, len);
    // iteractive_mergeSort(a, len);
    // recursive_merge_sort(a, len);
    // iteractive_merge_sort(a, len);
    // iteractive_merge_sort2(a, len);

    for (int i=0;i<len;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
