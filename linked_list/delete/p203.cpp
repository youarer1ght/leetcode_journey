#include <vector>
#include <algorithm>
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return head;
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        cur->next = head;
        ListNode* nex = head;
        while(nex){
            if(nex->val == val){
                cur->next = nex->next;
                nex = nex->next;
            } else {
                cur = nex;
                nex = nex->next;
            }
        }
        return dummy->next;
    }
};