#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> target;
        ListNode* curr = head;
        while(curr){
            if(target.count(curr)){
                return curr;
            }
            target.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};