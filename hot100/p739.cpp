#include <vector>
#include <stack>
using namespace std;
// 单调栈，只存储下标就可以
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty()){
            return {};
        }
        stack<pair<int, int>> s;
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!s.empty() && s.top().first < temperatures[i]){
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        while(!s.empty()){
            s.pop();
        }
        return result;
    }
};

int main(){
    vector<int> temperature = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    vector<int> result = s.dailyTemperatures(temperature);
}