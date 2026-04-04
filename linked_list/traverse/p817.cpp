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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> nums_set;
        for(int num: nums){
            nums_set.insert(num);
        }
        ListNode* curr = head;
        bool flag = false;
        int count = 0;
        while(curr){
            if(nums_set.count(curr->val)){
                flag = true;
            } else {
                if(flag){
                    count++;
                    flag = false;
                }
            }
            curr = curr->next;
        }
        if(flag){
            count++;
        }
        return count;
    }
};