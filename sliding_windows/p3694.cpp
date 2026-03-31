#include <string>
#include <unordered_set>
using namespace std;
class Solution {
private:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
public:
    int distinctPoints(string s, int k) {
        // init
        int count = 0;
        unordered_set<pair<int, int>, PairHash> Delta;
        pair<int, int> delta = {0, 0};
        for(int i = 0; i < k; i++){
            if(s[i] == 'U'){
                delta.second--;
            } else if(s[i] == 'D'){
                delta.second++;
            } else if(s[i] == 'L'){
                delta.first++;
            } else {
                delta.first--;
            }
        }
        Delta.insert(delta);
        for(int i = k; i < s.length(); i++){
            // pop
            if(s[i-k] == 'U'){
                delta.second++;
            } else if(s[i-k] == 'D'){
                delta.second--;
            } else if(s[i-k] == 'L'){
                delta.first--;
            } else {
                delta.first++;
            }
            // push
            if(s[i] == 'U'){
                delta.second--;
            } else if(s[i] == 'D'){
                delta.second++;
            } else if(s[i] == 'L'){
                delta.first++;
            } else {
                delta.first--;
            }
            Delta.insert(delta);
        }
        return Delta.size();
    }
};