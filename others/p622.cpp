#include <iostream>
#include <vector>
using namespace std;
// 数组
/*
class MyCircularQueue {
private:
    vector<int> v;
    int front, rear;
    int size;
    int capacity;
public:
    MyCircularQueue(int k) {
        v = vector<int>(k, 0);
        capacity = k;
        front = rear = size = 0;
    }
    
    bool enQueue(int value) {
        if(this->isFull()){
            return false;
        }
        v[rear] = value;
        rear = (++rear == capacity) ? 0: rear;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(this->isEmpty()){
            return false;
        }
        front = (++front == capacity) ? 0 : front;
        size--;
        return true;
    }
    
    int Front() {
        if(this->isEmpty()){
            return -1;
        }
        return v[front];
    }
    
    int Rear() {
        if(this->isEmpty()){
            return -1;
        }
        return v[rear==0 ? capacity - 1: rear - 1];
    }
    
    bool isEmpty() {
        if(size == 0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size == capacity){
            return true;
        }
        return false;
    }
};
*/
// 链表
// front->...->rear
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* ptr = nullptr) 
    : val(x), next(ptr) {}
};

class MyCircularQueue {
private:
    ListNode* front;
    ListNode* rear;
    int capacity;
    int size;
public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        front = rear = nullptr;
    }
    
    bool enQueue(int value) {
        if(this->isFull()){
            return false;
        }
        ListNode* node = new ListNode(value);
        if(this->isEmpty()){
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(this->isEmpty()){
            return false;
        }
        ListNode* toDelete = front;
        front = front->next;
        delete toDelete;
        size--;
        if(size == 0){
            rear = nullptr;
        }
        return true;
    }
    
    int Front() {
        if(this->isEmpty()){
            return -1;
        }
        return front->val;
    }
    
    int Rear() {
        if(this->isEmpty()){
            return -1;
        }
        return rear->val;
    }
    
    bool isEmpty() {
        if(size == 0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size == capacity){
            return true;
        }
        return false;
    }

    void showQueue(){
        ListNode* current = front;
        cout << "Queue: ";
        while(current != nullptr){
            cout << current->val << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main(){
    MyCircularQueue circularQueue(3); // 设置长度为 3
    // circularQueue.showQueue();
    circularQueue.enQueue(1);  // 返回 true
    // circularQueue.showQueue();
    circularQueue.enQueue(2);  // 返回 true
    // circularQueue.showQueue();
    circularQueue.enQueue(3);  // 返回 true
    // circularQueue.showQueue();
    circularQueue.enQueue(4);  // 返回 false，队列已满
    // circularQueue.showQueue();
    circularQueue.Rear();  // 返回 3
    // circularQueue.showQueue();
    circularQueue.isFull();  // 返回 true
    // circularQueue.showQueue();
    circularQueue.deQueue();  // 返回 true
    // circularQueue.showQueue();
    circularQueue.enQueue(4);  // 返回 true
    // circularQueue.showQueue();
    circularQueue.Rear();  // 返回 4
    // circularQueue.showQueue();
}