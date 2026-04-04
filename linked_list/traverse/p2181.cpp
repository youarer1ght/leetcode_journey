#include <vector>
#include <algorithm>
#include <iostream>
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        int sum = 0;
        ListNode* curr = head->next;
        ListNode* Dcurr = dummy;
        while(curr){
            if(curr->val != 0){
                sum += curr->val;
            } else {
                Dcurr->next = new ListNode(sum);
                Dcurr = Dcurr->next;
                sum = 0;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};