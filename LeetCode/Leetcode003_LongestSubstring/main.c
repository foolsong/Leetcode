//
//  main.c
//  Leetcode003_LongestSubstring
//
//  Created by 宋永建 on 2019/6/3.
//  Copyright © 2019 宋永建. All rights reserved.
//

#include <stdio.h>

#define ARRAY_SIZE_MAX  (1*1024*1024)

int lengthOfLongestSubstring(char * s){
    int arr[257] = {};
    int longest = 0;
    int longestTemp = 0;
    int flag = 0;
    int startIndex = 0;
    while (s[flag]) {
        int strInt = (int)s[flag];
        if (arr[strInt] > 0) {
            if (arr[strInt] -1  >= startIndex) {
                startIndex = arr[strInt];
                longestTemp = flag - (arr[strInt] -1 );
                arr[strInt] = flag + 1;
            } else {
                arr[strInt] = flag + 1;
                longestTemp += 1;
            }
            
        } else {
            longestTemp ++;
            arr[strInt] = flag + 1;
        }
        
        if (longest < longestTemp) {
            longest = longestTemp;
        }
        flag ++;
    }
    return longest;
}

int main(int argc, const char * argv[]) {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb")); // 3
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));    // 1
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));   // 3
    printf("%d\n", lengthOfLongestSubstring("abba"));     // 2
    printf("%d\n", lengthOfLongestSubstring("tmmzuxt"));  // 5
    return 0;
}
