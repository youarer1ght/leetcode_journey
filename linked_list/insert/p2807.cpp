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
private:
    int gcd(int a, int b){
        if(b > a){
            swap(a, b);
        }
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != nullptr){
            ListNode* ins = new ListNode(gcd(pre->val, cur->val));
            pre->next = ins;
            ins->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};