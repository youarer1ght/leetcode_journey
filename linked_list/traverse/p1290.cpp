#include <vector>
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
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        int sum = 0;
        while(curr != nullptr){
            sum <<= 1;
            sum += curr->val;
            curr = curr->next;
        }
        return sum;
    }
};