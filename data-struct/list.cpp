#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
}ListNode;


bool InsertList(ListNode*& head, int i, int e) {
    ListNode* cur = head;
    ListNode* new_node = new ListNode(e);
    cur->next = new_node;
    return true;
}


int main() {
    ListNode* head = new ListNode(1);
    InsertList(head, 1, 1);
    // cout << head->val << " ";
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    return 0;
}