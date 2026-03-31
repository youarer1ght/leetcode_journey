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
private:
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = reverseList(slow);
        
        bool result = true;
        ListNode* p1 = head;
        ListNode* p2 = mid;
        while(p2){
            if(p1->val != p2->val){
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        reverseList(mid);
        slow->next = nullptr;
        return result;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    ListNode* next = new ListNode(2);
    curr->next = next;
    curr = next;
    next = new ListNode(1);
    curr->next = next;
    curr = next;
    next = new ListNode(1);
    curr->next = next;
    curr = next;

    Solution s;
    bool result = s.isPalindrome(head);
    cout << (result ? "True" : "False") << endl;
}