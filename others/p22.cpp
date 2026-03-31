#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void backTrack(int n, int open, int close, string& curr, vector<string>& result) {
        if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }
        if (open < n) {
            curr += '(';
            backTrack(n, open + 1, close, curr, result);
            curr.pop_back();
        }
        if (close < open) {
            curr += ')';
            backTrack(n, open, close + 1, curr, result);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        backTrack(n, 0, 0, curr, result);
        return result;
    }
};