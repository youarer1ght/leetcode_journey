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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // 找到 left 的前一个节点
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // cur 指向 left 位置的节点，它将依次与后面的节点交换
        ListNode* cur = prev->next;
        
        // 头插法：将 cur 后面的节点插入到 prev 后面
        for (int i = left; i < right; i++) {
            ListNode* next = cur->next;      // 要移动的节点
            cur->next = next->next;          // cur 跳过 next
            next->next = prev->next;         // next 指向原 prev.next
            prev->next = next;               // prev 指向 next
        }
        
        return dummy->next;
    }
};