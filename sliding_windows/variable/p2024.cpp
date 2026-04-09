#include <string>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0;
        int maxT = 0, maxF = 0;
        int currT = 0, currF = 0;
        // T
        for(int right = 0; right < answerKey.length(); right++){
            if(answerKey[right] == 'T'){
                currT++;
            } else {
                currF++;
            }
            while(left <= right && currF > k){
                if(answerKey[left] == 'T'){
                    currT--;
                } else {
                    currF--;
                }
                left++;
            }
            maxT = max(maxT, currT + currF);
        }
        // F
        left = currT = currF = 0;
        for(int right = 0; right < answerKey.length(); right++){
            if(answerKey[right] == 'T'){
                currT++;
            } else {
                currF++;
            }
            while(left <= right && currT > k){
                if(answerKey[left] == 'T'){
                    currT--;
                } else {
                    currF--;
                }
                left++;
            }
            maxF = max(maxF, currT + currF);
        }
        return max(maxT, maxF);
    }
};