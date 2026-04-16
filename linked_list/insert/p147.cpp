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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* tail = head;      // 已排序部分的尾节点
        ListNode* cur = head->next; // 当前待排序节点
        
        while (cur) {
            if (cur->val >= tail->val) {
                // 当前节点比已排序部分的最大值还大，直接扩展尾部
                tail = cur;
                cur = cur->next;
            } else {
                // 需要插入到已排序部分的某个位置
                // 1. 从 dummy 开始找插入位置
                ListNode* prev = dummy;
                while (prev->next->val < cur->val) {
                    prev = prev->next;
                }
                
                // 2. 摘除 cur 节点
                tail->next = cur->next;
                
                // 3. 插入到 prev 之后
                cur->next = prev->next;
                prev->next = cur;
                
                // 4. 移动 cur 到下一个待排序节点
                cur = tail->next;
            }
        }
        
        return dummy->next;
    }
};