#include <vector>
#include <queue>
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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        ListNode dummy;
        ListNode* curr = &dummy;
        while(list1 && list2){
            if(list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
            } else {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }
        if(list1){
            curr->next = list1;
        }
        if(list2){
            curr->next = list2;
        }
        return dummy.next;
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if(left == right){
            return lists[left];
        }
        if(left > right){
            return nullptr;
        }
        int mid = left +  (right - left) / 2;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid+1, right);
        return merge2Lists(l1, l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        return merge(lists, 0, lists.size() - 1);
    }
};