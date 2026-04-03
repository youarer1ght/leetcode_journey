#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
private:
    const unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
public:
    int maxVowels(string s, int k) {
        // init
        int count = 0;  // 元音数量
        for(int i = 0; i < k; i++){
            if(vowel.count(s[i])){
                count++;
            }
        }
        int MaxCount = count;
        // 滑动
        for(int i = k; i < s.length(); i++){
            if(vowel.count(s[i-k])){
                count--;
            }
            if(vowel.count(s[i])){
                count++;
            }
            MaxCount = max(MaxCount, count);
        }
        return MaxCount;
    }
};