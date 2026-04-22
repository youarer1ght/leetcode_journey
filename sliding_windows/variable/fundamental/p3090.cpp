#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> win;
        int len = s.length();
        int maxLength = 0;
        int currLength = 0;
        for(int i = 0; i < len; i++){
            win[s[i]]++;
            currLength++;
            while(win[s[i]] > 2){
                char c = s[i - currLength + 1];
                win[c]--;
                if(win[c] == 0){
                    win.erase(c);
                }
                currLength--;
            }
            maxLength = max(maxLength, currLength);
        }
        return maxLength;
    }
};