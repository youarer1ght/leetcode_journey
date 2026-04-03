#include <vector>
using namespace std;
class Solution {
private:
    int init(vector<int>& code, int k, int& front, int& back){
        int n = code.size();
        int loop;
        if(k > 0){
            back = 1;
            front = (k + 1) % n;
            loop = k / n;
        } else {
            front = 0;
            back = n - (-k) % n;
            loop = (-k) % n;
        }
        int sumCode = 0;
        for(int i = 0; i < n; i++){
            sumCode += code[i];
        }
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if(k == 0){
            return result;
        }
        // init
        int sum = 0;
        for(int i = 0; i < k; i++){}
    }
};