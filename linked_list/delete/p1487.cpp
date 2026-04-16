#include  <deque>
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
    ListNode* removeNodes(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* cur = head;
        while(cur != nullptr){
            while(!dq.empty() && cur->val > dq.back()->val){
                dq.pop_back();
            }
            dq.push_back(cur);
            cur = cur->next;
        }
        ListNode* dummy = new ListNode();
        cur = dummy;
        while(!dq.empty()){
            cur->next = dq.front();
            dq.pop_front();
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};

/* 递归
ListNode* removeNodes(ListNode* head) {
    if (head == nullptr) return nullptr;           // 终止条件
    head->next = removeNodes(head->next);          // 递推：先处理右边
    if (head->next && head->val < head->next->val) // 回溯：决定是否删除
        return head->next;
    return head;
}
*/