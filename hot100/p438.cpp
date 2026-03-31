#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()){
            return {};
        }
        
        unordered_map<char, int> pCount;
        for (char c: p){
            pCount[c]++;
        }

        int pLength = p.length();
        vector<int> result;
        unordered_map<char, int> sCount;

        // Initialize the count for the first window of size pLength
        for(int i = 0; i < pLength; i++){
            sCount[s[i]]++;
        }
        if(sCount == pCount){
            result.push_back(0);
        }
        // Slide the window over string s
        for (int i = 1; i <= s.length() - pLength; i++){
            cout << "Window starting at index " << i << ": ";
            cout << s.substr(i, pLength) << endl;
            for(auto& pair : sCount){
                cout << pair.first << ":" << pair.second << " ";
            }
            cout << endl;
            // Remove the count of the character that is sliding out of the window
            if (i > 0){
                sCount[s[i - 1]]--;
                if (sCount[s[i - 1]] == 0){
                    sCount.erase(s[i - 1]);
                }
            }
            for(auto& pair : sCount){
                cout << pair.first << ":" << pair.second << " ";
            }
            cout << endl;
            // Add the count of the new character that is sliding into the window
            if (i + pLength - 1 < s.length()){
                sCount[s[i + pLength - 1]]++;
            }
            for(auto& pair : sCount){
                cout << pair.first << ":" << pair.second << " ";
            }
            cout << endl;
            if (sCount == pCount){
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = solution.findAnagrams(s, p);
    for (int index : result) {
        cout << index << " ";
    }
    printf("\n");
    return 0;
}