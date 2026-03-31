#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. 统计频率
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int num : nums) {
            maxFreq = max(maxFreq, ++freq[num]);
        }
        
        // 2. 桶排序：频率作为下标，存储对应元素
        vector<vector<int>> buckets(maxFreq + 1);   // 同一频率可能有多种元素
        for (auto& p : freq) {
            buckets[p.second].push_back(p.first);
        }
        
        // 3. 从高频率到低频率取元素
        vector<int> result;
        for (int i = maxFreq; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};