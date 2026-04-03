#include <vector>
using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime.front());
        for(int i = 1; i < startTime.size(); i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime - endTime.back());
        // init
        int curr = 0;
        for(int i = 0; i <= k; i++){
            curr += freeTime[i];
        }
        int maxTime = curr;
        // loop
        for(int i = k + 1; i < freeTime.size(); i++){
            curr = curr - freeTime[i-k-1] + freeTime[i];
            maxTime = max(maxTime, curr);
        }
        return maxTime;
    }
};