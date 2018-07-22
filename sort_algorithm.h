#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#ifdef __cplusplus
extern "C" {
#endif      
            
void heapSort(int a[], int n);
void mergeSort(int a[], int n);
void recursive_mergeSort(int a[], int n);
void iteractive_mergeSort(int a[], int n);
void quickSort(int a[], int n);

void testSort();

#ifdef __cplusplus
}
#endif 

#endif