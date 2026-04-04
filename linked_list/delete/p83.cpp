#include <vector>
#include <algorithm>
#include <unordered_set>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return nullptr;
        }
        unordered_set<int> nums_set;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        cur->next = head;
        ListNode* nex = head;
        while(nex){
            if(nums_set.count(nex->val)){
                cur->next = nex->next;
                nex = nex->next;
            } else {
                nums_set.insert(nex->val);
                cur = nex;
                nex = nex->next;
            }
        }
        return dummy->next;
    }
};