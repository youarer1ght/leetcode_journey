#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;  // 满足条件的字符种类数
        int start = 0, len = INT_MAX;  // 记录最小覆盖子串的起始位置和长度

        while(right < s.size()) {
            // 扩大窗口：将 s[right] 加入窗口
            char c = s[right];
            right++;
            if(need.count(c)) {
                window[c]++;
                if(window[c] == need[c]) {
                    valid++;
                }
            }

            // 当所有字符都满足条件时，尝试缩小窗口
            while(valid == need.size()) {
                // 更新最小覆盖子串
                if(right - left < len) {
                    start = left;
                    len = right - left;
                }

                // 缩小窗口：将 s[left] 移出窗口
                char d = s[left];
                left++;
                if(need.count(d)) {
                    if(window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
