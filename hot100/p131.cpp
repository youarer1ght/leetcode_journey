#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<vector<string>> result;
    vector<string> curr;
    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void backtrack(string s, int start){
        if(start == s.length()){
            result.push_back(curr);
            return;
        }
        for(int end = start; end < s.length(); end++){
            if(isPalindrome(s, start, end)){
                curr.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        curr.clear();
        backtrack(s, 0);
        return result;
    }
};