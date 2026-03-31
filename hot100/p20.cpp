#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            switch(c){
                case '(':
                    st.push('(');
                    break;
                case ')':
                    if(st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case '{':
                    st.push('{');
                    break;
                case '}':
                    if(st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                case '[':
                    st.push('[');
                    break;
                case ']':
                    if(st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    string str = "()[]{}";
    Solution s;
    bool result = s.isValid(str);
    cout << result << endl;
}