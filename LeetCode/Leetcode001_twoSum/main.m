//
//  main.m
//  Leetcode1_twoSum
//
//  Created by yjsong on 2019/5/27.
//  Copyright © 2019 宋永建. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node {
    int val;
    int index;
};
int comp(const void* a, const void* b) {
    return (((struct node*)a)->val > ((struct node*)b)->val ? 1 : -1);
}
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int n = numsSize;
    int begin = 0, end = n - 1;
    int* result = NULL;
    struct node* nodes = (struct node*)malloc(n * sizeof(struct node));
    // init nodes
    for(i = 0; i < n; i++) {
        nodes[i].val = nums[i];
        nodes[i].index = i;
    }
    qsort(nodes, n, sizeof(struct node), comp);
    while(begin < end) {
        if(nodes[begin].val + nodes[end].val == target) {
            result = (int*)malloc(sizeof(int) * 2);
            result[0] = nodes[begin].index;
            result[1] = nodes[end].index;
            free(nodes);
            return result;
        }
        else if(nodes[begin].val + nodes[end].val > target)
            end--;
        else
            begin++;
    }
    free(nodes);
    return result;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        NSLog(@"Hello, World!");
    }
    return 0;
}
