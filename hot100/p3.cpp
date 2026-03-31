#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charIndex;
        int maxLength = 0;
        int left = 0, right = 0;

        while(right < s.length()){
            // 如果当前字符不在当前窗口内，直接将其加入窗口
            if(charIndex.find(s[right]) == charIndex.end()){
                charIndex.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                // 如果当前字符已经在窗口内，说明出现了重复字符
                // 需要将窗口左边界向右移动，直到将重复字符移出窗口
                while(s[left] != s[right]){
                    charIndex.erase(s[left]);
                    left++;
                }
                // 移动左边界，将重复字符移出窗口
                charIndex.erase(s[left]);
                left++;
            }
        }
        return maxLength;
    }
};