#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode* next): val(val), next(next) {}
};

void InitList(ListNode*& head);
void PrintList(ListNode* head);

void ModifyList(ListNode* head, int) {
    while (head) {
        head->val = 10;
        head = head->next;
    }
}

void ModifyListPoint(ListNode* head, void*) {
    head = nullptr; // 无法修改指向
}

void ModifyListPoint(ListNode*& head, int) {
    head = nullptr;
}

// 引用遍历
void ReferenceTraversal(ListNode*& head) {
    ListNode* cur = head;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << '\n';
    // while (head) { // bad
    //     cout << head->val << ' ';
    //     head = head->next;
    // }
    // cout << '\n';
}

void ReverseList(ListNode*& head) {
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    head = pre;
}

ListNode* ReverseList(ListNode* head, int) { // bug: modify head ?
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode* ReverseList(ListNode* head, int, int) {
    if (!head) {
        return nullptr;
    }
    ListNode* res_head = new ListNode(head->val);
    ListNode* cur = head->next;
    while (cur) {
        ListNode* node = new ListNode(cur->val, res_head);
        res_head = node;
        cur = cur->next;
    }
    return res_head;
}

void fun(ListNode* head) {
    // ReverseList(head);
    ListNode* res = ReverseList(head, 0, 0);
    // PrintList(head); // 1
    PrintList(res);
}

int main() {
    ListNode* head = nullptr;
    InitList(head);
    // PrintList(head);

    // ReverseList(head);
    fun(head);
    PrintList(head);

    return 0;
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

void PrintList(ListNode* head) {
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}