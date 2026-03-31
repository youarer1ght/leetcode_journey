#include <stack>
using namespace std;
class SortedStack {
private:
    stack<int> s1, s2;
public:
    SortedStack(): s1(), s2(){
    }
    
    void push(int val) {
        if(this->isEmpty()){
            s1.push(val);
            return;
        }
        while(!s1.empty() && val > s1.top()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return;
    }
    
    void pop() {
        if(isEmpty()){
            return;
        }
        s1.pop();
    }
    
    int peek() {
        if(isEmpty()){
            return -1;
        }
        int val = s1.top();
        return val;
    }
    
    bool isEmpty() {
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */