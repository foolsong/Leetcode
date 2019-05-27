//
//  main.c
//  Leetcode15_3sum
//
//  Created by 宋永建 on 2019/3/1.
//  Copyright © 2019 宋永建. All rights reserved.
//

#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSort(int* nums,int first,int end){
    int temp,l,r;
    if(first >= end)return;
    temp = nums[first];
    l = first;r = end;
    while(l < r){
        while(l < r && nums[r] >= temp) r--;
        if(l < r) nums[l] = nums[r];
        while(l < r && nums[l] <= temp)l++;
        if(l < r) nums[r] = nums[l];
    }
    nums[l] = temp;
    quickSort(nums,first,l-1);
    quickSort(nums,l+1,end);
}

void quickSort1(int* nums,int first,int end) {
    int temp, l, r;
    if (first >= end) {
        return;
    }
    l = first;
    r = end;
    temp = nums[first];
    while (l < r) {
        while (l < r && nums[r] >= temp) {
            r--;
        }
        if (l < r) {
            nums [l] = nums [r];
        }
        while (l < r && nums[l] <= temp) {
            l++;
        }
        if (l < r) {
            nums[r] = nums[l];
        }
    }
    nums[l] = temp;
    quickSort1(nums, first,l - 1);
    quickSort1(nums, l + 1, end);
}


int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i,sum,top = -1,begin,end;
    int** res = (int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6);
    if(numsSize<3){
        *returnSize=0;
        return res;
    }
    //将nums从小到大进行排序
    quickSort1(nums,0,numsSize-1);
    
    for(i=0;i<numsSize;i++){
        //从左到右(从小到大)取出一个负数
        if(nums[i]>0)break;
        if(i>0 && nums[i]==nums[i-1])continue;
        //分别找出比这个负数大的最大的数end和最小的数begin
        begin=i+1;end=numsSize-1;
        //最小的数begin比最大的数小end
        while(begin<end){
            sum=nums[i]+nums[begin]+nums[end];
            if(sum==0){
                //记录长度
                top++;
                res[top]=(int*)malloc(sizeof(int)*3);
                res[top][0]=nums[i];res[top][1]=nums[begin];res[top][2]=nums[end];
                begin++;end--;
                while(begin<end && nums[begin]==nums[begin-1])begin++;
                while(begin<end && nums[end]==nums[end+1])end--;
            }else if(sum>0) end--;//如果和大于0，则将最大的数缩小
            else begin++;//如果和小于0，则将最小的数扩大
        }
    }
    *returnSize=top+1;
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int returnSize;
    
    int **re = threeSum(nums, 6,&returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t",re[i][j]);
        }
        printf("\n");
    }
    printf("Hello, World!\n");
    return 0;
}

