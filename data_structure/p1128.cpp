#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;  // 编码 -> 出现次数
        int count = 0;
        
        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            // 标准化编码：小的在前，用两位数编码（因为 1 <= a,b <= 9）
            int code = min(a, b) * 10 + max(a, b);
            // 先累加已有的对数，再增加计数
            count += freq[code];
            freq[code]++;
        }
        return count;
    }
};