#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> re;  // 记录符合条件的 string
        // 实则只取最短即可，长中含短，所以最长出现在短
        for(int len = minSize; len <= maxSize; len++){
            unordered_map<char, int> count; // 计数 letters
            // init
            string curr = s.substr(0, len);
            for(char c: curr){
                count[c]++;
            }
            if(count.size() <= maxLetters){
                re[curr]++;
            }
            // loop
            for(int i = len; i < s.size(); i++){
                // pop
                count[s[i - len]]--;
                if(count[s[i - len]] == 0){
                    count.erase(s[i - len]);
                }
                // push
                count[s[i]]++;
                // check
                curr = s.substr(i - len + 1, len);  // 注意+1
                if(count.size() <= maxLetters){
                    re[curr]++;
                }
            }
        }
        int maxCount = 0;
        for(pair<string, int> p: re){
            maxCount = max(maxCount, p.second);
        }
        return maxCount;
    }
};