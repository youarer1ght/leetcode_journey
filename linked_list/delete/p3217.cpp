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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> nums_set;
        for(int num: nums){
            nums_set.insert(num);
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        cur->next = head;
        ListNode* nex = head;
        while(nex){
            if(nums_set.count(nex->val)){
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