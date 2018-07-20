#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include "sort_algorithm.h"
#include "BiNode.h"
#include "ListTest.h"
#include "merge_sort.h"
#include "DoubleList.h"

int binarySearch(int a[], int n, int value);

void levelViewBiTree(PBiNode tree) {
    if (tree == NULL) return;
    std::queue<PBiNode> _queue;
    _queue.push(tree);
    int count = 1;
    while(!_queue.empty()) {
        PBiNode node = _queue.front();
        _queue.pop();
        count--;
        printf("%d ", node->data);
        if (node->left != NULL) _queue.push(node->left);
        if (node->right != NULL) _queue.push(node->right);

        if (count <= 0) {
            printf("\n");
            count = _queue.size();
        }
    }
}

void testAVLTree() {
    PBiNode root = (PBiNode)malloc(sizeof(BiNode));
    PBiNode node1 = (PBiNode)malloc(sizeof(BiNode));
    PBiNode node2 = (PBiNode)malloc(sizeof(BiNode));
    PBiNode node3 = (PBiNode)malloc(sizeof(BiNode));
    root->left = node1;
    root->data = 1;
    root->right = node2;

    node1->data = 2;
    node1->left = node3;
    node1->right = NULL;

    node2->data = 3;
    node2->left = NULL;
    node2->right = NULL;

    node3->data = 4;
    node3->left = NULL;
    node3->right = NULL;

    std::cout<<"\n前序遍历"<<std::endl;
    previewBiTree(root);

    std::cout<<"\n后续遍历"<<std::endl;
    suffixViewBiTree(root);

    std::cout<<"\n中序遍历"<<std::endl;
    middleViewBiTree(root);

    std::cout<<"\n层序遍历"<<std::endl;
    levelViewBiTree(root);
    printf("\n");
    bool isBalance = true;
    isBalance = (isBalanceBiTree(root) == 1);
    std::cout<<"isBalance="<<(isBalance?"true":"false")<<std::endl;

    PBiNode node4 = (PBiNode)malloc(sizeof(BiNode));
    node4->data = 5;
    node4->left = NULL;
    node4->right = NULL;
    // node2->left = node4;
    node3->left = node4;

    std::cout<<"\n前序遍历"<<std::endl;
    previewBiTree(root);

    std::cout<<"\n后续遍历"<<std::endl;
    suffixViewBiTree(root);

    std::cout<<"\n中序遍历"<<std::endl;
    middleViewBiTree(root);

    std::cout<<"\n层序遍历"<<std::endl;
    levelViewBiTree(root);
    printf("\n");
    isBalance = true;
    isBalance = isBalanceBiTree(root);
    std::cout<<"isBalance="<<(isBalance?"true":"false")<<std::endl;

    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
}

std::string getMaxRepeatString(const std::string &aString);
void testMiddle();

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

int main(int argc, char* argv[]) {
    std::cout<<"hello world"<<std::endl;
/**
    int a[] = {2,3,5,6,9,10,23,34,43,45,65};

    int index = binarySearch(a, 11, 34);
    std::cout<<"index="<<index<<std::endl;

    index = binarySearch(a, 11, -10);
    std::cout<<"index="<<index<<std::endl;

    index = binarySearch(a, 11, 100);
    std::cout<<"index="<<index<<std::endl;

    index = binarySearch(a, 11, 9);
    std::cout<<"index="<<index<<std::endl;
**/
    // testAVLTree();

    // std::string str = "banana";
    // std::string maxRepeatStr = getMaxRepeatString(str);
    // std::cout<<"origin str = "<<str<<std::endl;
    // std::cout<<"max repeat str = "<<maxRepeatStr<<std::endl;

    // testMiddle();
    testSort();

    // ListTest *listTest = new ListTest();
    // listTest->test();
    // delete listTest;

    // testDoubleList();

    std::cout<<"end"<<std::endl;
    return 0;
}

int binarySearch(int a[], int n, int value) {
    if (n <= 0 || a == NULL) return -1;

    long l = 0, h = n-1;
    long mid = (l+h)/2;

    while ( l <= h) {
        if (a[mid] == value) return mid;
        else if (a[mid] > value) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
        mid = (l + h)/2;
    }
    return -1;
}

std::string getMaxRepeatString(const std::string &aString) {
    std::vector<std::string> suffixStrings;
    for (int i=0;i<aString.length();i++) {
        suffixStrings.push_back(aString.substr(i));
    }
    sort(suffixStrings.begin(), suffixStrings.end());
    int index = 0, maxLen = 0;
    for (int i=0;i<suffixStrings.size()-1;i++) {
        std::string string1 = suffixStrings[i];
        std::string string2 = suffixStrings[i+1];
        int j=0;
        while(j<string1.length() && j<string2.length() && string1[j] == string2[j]) j++;
        if (maxLen < j) {
            index = i;
            maxLen = j;
        }
    }
    return suffixStrings[index].substr(0, maxLen);
}

int middleOfArrays(int a[], int n, int b[], int m) {
    if (a == NULL && b == NULL) return 0;
    int i=0, j=0;
    int allCount = n + m;
    // int middle = allCount%2 == 1 ? (allCount/2): (allCount/2+1);
    int middle = (allCount/2);
    int k = 0;
    int lastItem = 0; 
    int curItem = 0;
    while(k<=middle) {
        lastItem = curItem;
        if (i<n && j<m) {
            if (a[i]<b[j]) {
                curItem = a[i];
                i++;
                k++;
            }  else {
                curItem = b[j];
                j++;
                k++;
            }
        } else if (i<n) {
            curItem = a[i];
            i++;
            k++;
        } else if (j<m) {
            curItem = b[j];
            j++;
            k++;
        }
    }
    if (allCount%2 == 1) return curItem;
    else return (curItem+lastItem)/2;
}

void testMiddle() {
    int a[] = {1,2,3,4,5,6,7,8,};
    // int b[] = {11,12,13,14,15,16,17,18,19, 20};
    int b[] = {1,2,3,4,5,6,7,8,9};
    int middle = middleOfArrays(a, 8, b, 9);
    printf("\nmiddle=%d\n", middle);
}