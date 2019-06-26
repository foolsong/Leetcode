//
//  main.c
//  Leetcode004_MedianOfArrays
//
//  Created by 宋永建 on 2019/6/4.
//  Copyright © 2019 宋永建. All rights reserved.
//

/*
 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 你可以假设 nums1 和 nums2 不会同时为空。
 
 示例 1:
 nums1 = [1, 3]
 nums2 = [2]
 则中位数是 2.0
 
 
 示例 2:
 nums1 = [1, 2]
 nums2 = [3, 4]
 则中位数是 (2 + 3)/2 = 2.5
 
 
 */

// 参考 https://www.cnblogs.com/YaoDD/p/5205554.html

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int* longNumList;
    int* shortNumList;

    int shortNumListSize = 0;
    int longNumListSize = 0;
    
    if (nums1Size > nums2Size) {
        longNumList = nums1;
        shortNumList = nums2;
        
        shortNumListSize = nums2Size;
        longNumListSize = nums1Size;
    } else {
        longNumList = nums2;
        shortNumList = nums1;
        
        shortNumListSize = nums1Size;
        longNumListSize = nums2Size;
    }
    
    
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int num1[] = {1 , 3};
    int num2[] = {2};
    
    printf("%.1f\n",findMedianSortedArrays(num1, 2, num2, 1));
    return 0;
}
