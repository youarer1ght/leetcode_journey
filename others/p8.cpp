#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> permutation(string S) {
        int length = S.length();
        map<char, int> charCount;   // unordered_map<char, int> 也可以，但 map 会自动排序，结果更有序
        for (char c: S){
            charCount[c]++;
        }
        vector<string> result;
        string current;
        BackTrack(charCount, current, result, length);
        return result;
    }
private:
    void BackTrack(map<char, int>& charCount, string current, vector<string>& result, const int length){
        if(current.length() == length){
            result.push_back(current);
            return;
        }
        for(auto& p: charCount){
            if(p.second > 0){
                p.second--;
                BackTrack(charCount, current + p.first, result, length);
                p.second++;
            }
        }
    }
};

int main(){
    Solution s;
    string S = "abc";
    vector<string> result = s.permutation(S);
    for(string& str: result){
        printf("%s\n", str.c_str());
    }
    return 0;
}