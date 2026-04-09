#include <vector>
#include <climits>
#include <deque>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int n = arrays.size();
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();
        for(int i = 1; i < n; i++){
            res = max(res, max(arrays[i].back() - minVal, maxVal - arrays[i].front()));
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }
        return res;
    }
};