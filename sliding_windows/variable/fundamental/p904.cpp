#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // init
        int n = fruits.size();
        unordered_map<int, int> bucket;
        int f = 0;
        int maxCount = 0;
        int currCount = 0;
        for(int i = 0; i < n; i++){
            bucket[fruits[i]]++;
            currCount++;
            while(f <= i && bucket.size() > 2){
                bucket[fruits[f]]--;
                currCount--;
                if(bucket[fruits[f]] == 0){
                    bucket.erase(fruits[f]);
                }
                f++;
            }
            maxCount = max(maxCount, currCount);
        }
        return maxCount;
    }
};