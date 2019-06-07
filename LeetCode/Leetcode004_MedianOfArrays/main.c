//
//  main.c
//  Leetcode004_MedianOfArrays
//
//  Created by 宋永建 on 2019/6/4.
//  Copyright © 2019 宋永建. All rights reserved.
//

#include <stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int numCount = 0;
    int listSize = 0;
    if ((nums1Size + nums2Size) % 2 ==1) {
        numCount = 1;
        listSize = (nums1Size + nums2Size) / 2;
    } else {
        numCount = 1;
        listSize = (nums1Size + nums2Size) / 2 + 1;
    }
    int list[listSize];
    
}

int main(int argc, const char * argv[]) {
    printf("Hello, World!\n");
    return 0;
}
