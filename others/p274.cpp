#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()){
            return 0;
        }
        int n = citations.size();
        // 计数每个引用量有几篇文章
        vector<int> count(n+1, 0);
        for(int i: citations){
            if(i > n){
                count[n]++;
            } else {
                count[i]++;
            }
        }
        // 从大到小遍历
        int sum = 0;
        for(int i = n; i >= 0; i--){
            sum += count[i];
            if(sum >= i){
                return i;
            }
        }
        return 0;
    }
};