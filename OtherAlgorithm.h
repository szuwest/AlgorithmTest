#ifndef __OTHER_ALGORITHM__H
#define __OTHER_ALGORITHM__H

#include <string>

// #ifdef __cplusplus 
// extern "C" {
// #endif

int binarySearch(int a[], int n, int value);
void testBinarySearch();

std::string getMaxRepeatString(const std::string &aString);
void testMaxRepeatString();

int middleOfArrays(int a[], int n, int b[], int m);
void testMiddle();

// #ifdef __cplusplus 
// }
// #endif

#endif