#include "../head-file.h"

/*
problme: LCR 025. 两数相加 II
给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
可以假设除了数字 0 之外，这两个数字都不会以零开头。
输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
数据范围：
    链表的长度范围为 [1, 100]
    0 <= node.val <= 9
    输入数据保证链表代表的数字无前导 0
url: https://leetcode.cn/problems/add-two-numbers-ii/
@Author: Eorys
@Date: 2023-08-14 18:57:00
@Last Modified by: Eorys
@Last Modified time: 2023-08-14 18:57:00
@Description:
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode* next): val(val), next(next) {}
};

// 翻转链表
class Solution {
private:
    // O(n)
    void ReverseList(ListNode*& head) {
        ListNode* cur = head;
        if (!cur) {
            return;
        }
        while (cur && cur->next) {
            ListNode* next_next_node = cur->next->next;
            ListNode* next_node = cur->next;
            ListNode* cur_node = cur;
            head = next_node;
            head->next = cur_node;
            
            next_node->next = cur_node;
            cur_node->next = next_next_node;
            head = next_node;
            cur = cur->next;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ReverseList(l1);
    }
};

// 栈
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    }
};


void PrintList(ListNode* head);
void InitList(ListNode*& head);

int main() {
    ListNode* head1 = nullptr, * head2 = nullptr;
    InitList(head1);
    InitList(head2);

    PrintList(head1);
    PrintList(head2);

    Solution s;
    ListNode* res_head = s.addTwoNumbers(head1, head2);
    PrintList(res_head);
    return 0;
}

void PrintList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << '\n';
}

void InitList(ListNode*& head) {
    ListNode* cur = head;
    int len = 0;
    cin >> len;
    while (len--) {
        int val = 0;
        cin >> val;
        if (!cur) {
            head = cur = new ListNode(val);
        }
        else {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }
}