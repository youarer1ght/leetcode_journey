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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* pre = dummy;
        pre->next = list1;
        ListNode* cur = list1;
        for(int i = 0; i < a; i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = list2;
        for(int i = a; i < b; i++){
            cur = cur->next;
        }
        while(pre->next != nullptr){
            pre = pre->next;
        }
        pre->next = cur->next;
        return list1;
    }
};