//
//  main.cpp
//  LeetCode
//
//  Created by 宋永建 on 2019/1/21.
//  Copyright © 2019 宋永建. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = new ListNode(-1);
    ListNode *cur = res;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry) cur->next = new ListNode(1);
    return res->next;
}

int main(int argc, const char * argv[]) {
    
    ListNode *res1 = new ListNode(-1);
    ListNode *cur1 = res1;
    cur1->val = 2;
    cur1->next = new ListNode(4);
    cur1 = cur1->next;
    cur1->next = new ListNode(3);
    
    ListNode *res2 = new ListNode(-1);
    ListNode *cur2 = res2;
    cur2->val = 5;
    cur2->next = new ListNode(6);
    cur2 = cur2->next;
    cur2->next = new ListNode(4);
    
    
    ListNode *listNode = addTwoNumbers(res1, res2);
    
    while (listNode) {
        std::cout << listNode->val;
        listNode = listNode->next;
    }
    
    std::cout << "\n";
    
    return 0;
}
