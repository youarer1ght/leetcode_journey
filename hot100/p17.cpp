#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;  // 输入为空，返回空结果
        // 数字到字母的映射
        vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current;  // 当前组合
        backtrack(result, mapping, digits, current, 0);
        return result;
    }
private:
    void backtrack(vector<string>& result, const vector<string>& mapping, const string& digits, string current, int index) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        int digit = digits[index] - '0';
        for (char c : mapping[digit]) {
            backtrack(result, mapping, digits, current + c, index + 1);
        }
    }
};