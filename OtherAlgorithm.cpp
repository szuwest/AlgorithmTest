#include "OtherAlgorithm.h"
#include <iostream>
#include <vector>

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

void testBinarySearch() {
    int a[] = {2,3,5,6,9,10,23,34,43,45,65};

    int index = binarySearch(a, 11, 34);
    std::cout<<"index="<<index<<std::endl;

    index = binarySearch(a, 11, -10);
    std::cout<<"index="<<index<<std::endl;

    index = binarySearch(a, 11, 100);
    std::cout<<"index="<<index<<std::endl;

    index = binarySearch(a, 11, 9);
    std::cout<<"index="<<index<<std::endl;
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

void testMaxRepeatString() {
    std::string str = "banana";
    std::string maxRepeatStr = getMaxRepeatString(str);
    std::cout<<"origin str = "<<str<<std::endl;
    std::cout<<"max repeat str = "<<maxRepeatStr<<std::endl;
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