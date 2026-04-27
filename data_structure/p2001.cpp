#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    // 求最大公约数（欧几里得算法）
    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    
    // 返回矩形的最简整数比
    pair<int, int> getRatio(const vector<int>& rect) {
        int w = rect[0], h = rect[1];
        int g = gcd(w, h);
        return {w / g, h / g};
    }
    
    // 自定义 pair 的哈希函数
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<long long>()((static_cast<long long>(p.first) << 32) | p.second);
        }
    };
    
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<pair<int, int>, int, PairHash> freq;
        long long count = 0;  // 必须用 long long
        
        for (const auto& rect : rectangles) {
            auto ratio = getRatio(rect);
            count += freq[ratio];  // 累加已有的数量（这是对数公式的变形）
            freq[ratio]++;
        }
        
        return count;
    }
};