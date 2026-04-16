#include <cstddef>
using namespace std;
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        if(head->next == head){
            head->next = new Node(insertVal);
            head->next->next = head;
            return head;
        }
        Node* cur = head;
        Node* nex = head->next;
        while(cur->val <= nex->val && (nex != head)){
            cur = nex;
            nex = nex->next;
        }
        if(!(insertVal >= cur->val || insertVal <= nex->val)){
            while(nex->val < insertVal){
                cur = nex;
                nex = nex->next;
            }
        }
        cur->next = new Node(insertVal);
        cur->next->next = nex;
        return head;
    }
};