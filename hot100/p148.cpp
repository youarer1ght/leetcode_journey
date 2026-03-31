#include <vector>
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        // merge
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        // 左右排序后连接
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(left && right){
            if(left->val > right->val){
                curr->next = right;
                right = right->next;
                curr = curr->next;
            } else {
                curr->next = left;
                left = left->next;
                curr = curr->next;
            }
        }
        curr->next = left ? left : right;
        return dummy.next;
    }
};