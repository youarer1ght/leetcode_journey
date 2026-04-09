#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minprice = prices[0];   // 左边最小
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            minprice = min(minprice, prices[i-1]);
            profit = max(profit, prices[i] - minprice);
        }
        return profit;
    }
};