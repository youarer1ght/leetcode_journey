#include <vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int init = 0;
        int increase = 0;
        for(int i = 0; i < n; i++){
            init += customers[i] * (1 - grumpy[i]);
        }
        for(int i = 0; i < minutes; i++){
            increase += customers[i] * grumpy[i];
        }
        int maxIncrease = increase;
        // loop
        for(int i = minutes; i < n; i++){
            increase = increase - customers[i-minutes]*grumpy[i-minutes] + customers[i]*grumpy[i];
            maxIncrease = max(maxIncrease, increase);
        }
        return maxIncrease + init;
    }
};