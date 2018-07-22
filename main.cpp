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
#include "CNode.h"
#include "OtherAlgorithm.h"

int main(int argc, char* argv[]) {
    std::cout<<"hello world"<<std::endl;

    testBinarySearch();

    testAVLTree();

    testMaxRepeatString();

    testMiddle();
    testSort();
    test_Single_List();
    // ListTest *listTest = new ListTest();
    // listTest->test();
    // delete listTest;

    // testDoubleList();

    std::cout<<"end"<<std::endl;
    return 0;
}
