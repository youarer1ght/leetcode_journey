using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        // 复制
        Node* curr = head;
        while(curr){
            Node* node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
            curr = curr->next->next;
        }
        // 添加random
        curr = head;
        while(curr && curr->next){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // 拆开
        Node* dummy = new Node(0);
        Node* copy = dummy;
        curr = head;
        while(curr && curr->next){
            copy->next = curr->next;
            curr->next = curr->next->next;
            copy = copy->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};