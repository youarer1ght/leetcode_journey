#include <vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i = 0; i < k ; i++){
            sum += cardPoints[i];
        }
        int maxSum = sum;
        int n = cardPoints.size();
        for(int i = 1; i <= k; i++){
            sum  = sum - cardPoints[k - i] + cardPoints[n - i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};