#include <vector>
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
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        
        // 1. 计算链表长度
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        
        // 2. 计算每部分的长度
        int len = n / k;        // 每部分基础长度
        int remainder = n % k;  // 前 remainder 部分多一个节点
        
        curr = head;
        // 3. 分割链表
        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            
            // 当前部分应该有的长度
            int partSize = len + (i < remainder ? 1 : 0);
            
            // 移动到当前部分的最后一个节点
            for (int j = 0; j < partSize - 1; j++) {
                curr = curr->next;
            }
            
            // 切断链表
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        
        return result;
    }
};