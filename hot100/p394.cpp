#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string curr;
        int k = 0;
        for(char c: s){
            if(isdigit(c)){
                k = k * 10 + c - '0';
            } else if(c == '['){
                countStack.push(k);
                strStack.push(curr);
                k = 0;
                curr.clear();
            } else if(c == ']'){
                int repeat = countStack.top();
                countStack.pop();
                string prev = strStack.top();
                strStack.pop();
                for(int i = 0; i < repeat; i++){
                    prev += curr;
                }
                curr = prev;
            } else {
                curr += c;
            }
        }
        return curr;
    }
};