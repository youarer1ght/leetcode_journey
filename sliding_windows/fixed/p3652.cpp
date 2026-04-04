#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        // origin
        long long maxP = 0;
        for(int i = 0; i < prices.size(); i++){
            // 不强制转化会整型溢出
            maxP += (long long)prices[i] * strategy[i];
        }
        // init
        long long currP = maxP;
        for(int i = 0; i < k/2; i++){
            currP += (long long)prices[i] * (0 - strategy[i]);
        }
        for(int i = k/2; i < k; i++){
            currP += (long long)prices[i] * (1 - strategy[i]);
        }
        maxP = max(maxP, currP);
        // loop
        for(long long i = k; i < prices.size(); i++){
            // pop & push
            currP += (long long)prices[i-k] * (strategy[i-k] - 0);
            currP += (long long)prices[i-k/2] * (0 - 1);
            currP += (long long)prices[i] * (1 - strategy[i]);
            // check
            maxP = max(maxP, currP);
        }
        return maxP;
    }
};  

int main(){
    Solution s;
    vector<int> prices = {4, 2, 8};
    vector<int> strategy = {-1, 0, 1};
    int k = 2;
    long long maxP = s.maxProfit(prices, strategy, k);
    cout << maxP;
}