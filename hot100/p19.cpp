#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        size_t sz = 0;
        ListNode* curr = head;
        while(curr){
            sz++;
            curr = curr->next;
        }
        if(sz == 1){
            return nullptr;
        }
        if(sz == n){
            curr = head->next;
            return curr;
        }
        curr = head;
        // curr指向要删除节点的前一个节点
        for(int i = 0; i < sz - n - 1; i++){
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};