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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if((head == nullptr) || (head->next == nullptr) || (head->next->next == nullptr)){
            return {-1, -1};
        }
        int minDistance = -1;
        int maxDistance = -1;
        int currDistance = -1;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nex = head->next->next;
        while(nex){
            if(currDistance >= 0){
                currDistance++;
            }
            if((cur->val > pre->val && cur->val > nex->val)
            || (cur->val < pre->val && cur->val < nex->val)){
                minDistance = minDistance < 0 ? currDistance : min(minDistance, currDistance);
                if(currDistance >= 0){
                    maxDistance += currDistance;
                }
                currDistance = 0;
            }
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        if(maxDistance >= 0){
            maxDistance++;
        }
        return {minDistance, maxDistance};
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(4);
    ListNode* curr = head;
    curr->next = new ListNode(2);
    curr = curr->next;
    curr->next = new ListNode(4);
    curr = curr->next;
    curr->next = new ListNode(1);
    curr = curr->next;
    vector<int> result = s.nodesBetweenCriticalPoints(head);
    cout << '[' << result[0] << ", " << result[1] << ']';
}