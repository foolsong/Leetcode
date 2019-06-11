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
    int numCount = 0;
    int listSize = (nums1Size + nums2Size);
    if ((nums1Size + nums2Size) % 2 == 1) {
        numCount = 1;
    } else {
        numCount = 2;
    }
    
    int* longNum;
    int* shortNum;
    int longIndex = 0;
    int shortIndex = 0;
    int shortSize = 0;
    int longSize = 0;
    if (nums1Size > nums2Size) {
        longIndex = (int)((nums1Size - 1) * 0.5);
        shortIndex = (int)((nums2Size - 1) * 0.5);
        
        longNum = nums1 + longIndex;
        shortNum =  nums2 + shortIndex;
        
        shortSize = nums2Size;
        longSize = nums1Size;
    } else {
        longIndex = (int)((nums2Size - 1) * 0.5);
        shortIndex = (int)((nums1Size - 1) * 0.5);
        
        longNum = nums2 +longIndex;
        shortNum = nums1 + shortIndex;
        
        shortSize = nums1Size;
        longSize = nums2Size;
    }
    
    if (shortSize < 1) {
        if (longSize % 2 == 1) {
            return *longNum;
        } else {
            return (*longNum + *(longNum + 1)) * 0.5;
        }
    }
    
    if (*longNum < *shortNum) {
        while (*longNum <= *shortNum && shortIndex > 0) {
            shortNum--;
            shortIndex--;
        }
        
        while (longIndex + 1 < longSize && *(longNum + 1) < *shortNum) {
            longNum++;
            longIndex++;
        }
        
        int goalIndex = (int)(listSize + 1) * 0.5 ;
        while (goalIndex != (shortIndex + longIndex + 2)) {
            if (*longNum > *shortNum && shortIndex + 1 < shortSize) {
                shortIndex++;
                shortNum++;
            } else if ( longIndex + 1 < longSize){
                longIndex++;
                longNum++;
            }
        }
           
        
    } else {
        while (*longNum >= *shortNum && (shortIndex + 1) < shortSize) {
            shortNum++;
            shortIndex++;
        }
        
        while (longIndex > 0 && *(longNum - 1) > *shortNum) {
            longNum--;
            longIndex--;
        }
        
        int goalIndex = (int)(listSize + 1) * 0.5 ;
        while (goalIndex != (shortIndex + longIndex + 2)) {
            if (*longNum > *shortNum && longIndex > 0) {
                longIndex--;
                longNum--;
                
            } else if (shortIndex + 1 < shortSize){
                shortIndex--;
                shortNum--;
            } else {
                    if (numCount == 1) {
                        return *shortNum ;
                    } else {
                        int goal = *shortNum;
                        if (shortIndex + 1 < shortSize) {
                            shortNum++;
                            return (goal + (*longNum > *shortNum ? *shortNum : *longNum)) * 0.5;
                        }
                        return (goal + *longNum) * 0.5;
                    }
            }
        }
        
    }
    
    if (numCount == 1) {
        return *longNum > *shortNum ? *longNum : *shortNum;
    } else {
        int goal;
        if (*longNum > *shortNum) {
            goal = *longNum ;
        } else {
            goal = *shortNum;
        }
        if (shortIndex + 1 < shortSize) {
            shortNum++;
        }
        if (longIndex + 1 < longSize) {
            longNum++;
        }
        
        return (goal + (*longNum > *shortNum ? *longNum : *shortNum)) * 0.5;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int num1[] = {1 , 3};
    int num2[] = {2};
    
    printf("%.1f\n",findMedianSortedArrays(num1, 2, num2, 1));
    return 0;
}
