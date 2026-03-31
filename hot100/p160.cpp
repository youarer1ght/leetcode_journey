#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        // 当pA和pB都走到NULL时会同时结束
        while (pA != pB) {
            // pA走到末尾后转向headB
            pA = pA ? pA->next : headB;
            // pB走到末尾后转向headA
            pB = pB ? pB->next : headA;
        }
        // 返回交点或NULL
        return pA;
    }
};