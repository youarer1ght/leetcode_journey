#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        
        if (k == 0) return res;
        
        int m = abs(k);
        
        if (k > 0) {
            // 计算第一个窗口
            int sum = 0;
            for (int i = 1; i <= m; i++) {
                sum += code[i % n];
            }
            res[0] = sum;
            
            // 滑动窗口
            for (int i = 1; i < n; i++) {
                sum -= code[i];
                sum += code[(i + m) % n];
                res[i] = sum;
            }
        } else {
            // k < 0
            // 计算第一个窗口：前 m 个元素（循环意义上）
            int sum = 0;
            for (int i = n - m; i < n; i++) {
                sum += code[i];
            }
            res[0] = sum;
            
            // 滑动窗口
            for (int i = 1; i < n; i++) {
                sum -= code[(i - 1 - m + n) % n];
                sum += code[i - 1];
                res[i] = sum;
            }
        }
        
        return res;
    }
};