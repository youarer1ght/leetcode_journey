#include <vector>
#include <algorithm>
#include <unordered_set>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        cur->next = head;
        ListNode* nex = head;
        bool flag = false;
        while(nex && nex->next){
            if(nex->val == nex->next->val){
                nex = nex->next;
                flag = true;
            } else {
                if(flag){
                    cur->next = nex->next;
                    nex = nex->next;
                    flag = false;
                } else {
                    cur = nex;
                    nex = nex->next;
                }
            }
        }
        if(flag){
            cur->next = nullptr;
        }
        return dummy->next;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    curr->next = new ListNode(1);
    curr = curr->next;
    curr->next = new ListNode(1);
    curr = curr->next;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(3);
    curr = curr->next;
    curr->next = new ListNode(3);
    curr = curr->next;
    ListNode* result = s.deleteDuplicates(head);
    curr = result;
    while(curr){
        cout << curr->val << "->";
        curr = curr->next;
    }
    return 0;
}