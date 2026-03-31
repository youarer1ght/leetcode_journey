#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
private:
    const unordered_set<char> vowels = {
        'a', 'e', 'i', 'o', 'u',
        'A', 'E', 'I', 'O', 'U'
    };
    bool isVowelString(string word){
        if(vowels.count(word.front()) && vowels.count(word.back())){
            return true;
        }
        return false;
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++){
            if(isVowelString(words[i])){
                count++;
            }
        }
        return count;
    }
};