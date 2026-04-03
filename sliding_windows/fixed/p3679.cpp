#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, int> freq;
        int count = 0;
        // init
        for(int i = 0; i < w; i++){
            if(freq[arrivals[i]] == m){
                arrivals[i] = 0 - arrivals[i];
                count++;
            } else {
                freq[arrivals[i]]++;
            }
        }
        for(int i = w; i < arrivals.size(); i++){
            // pop
            if(arrivals[i-w] < 0){
                arrivals[i-w] = 0 - arrivals[i-w];
            } else {
                freq[arrivals[i-w]]--;
                if(freq[arrivals[i-w]] == 0){
                    freq.erase(arrivals[i-w]);
                }
            }
            // push
            if(freq[arrivals[i]] == m){
                arrivals[i] = 0 - arrivals[i];
                count++;
            } else {
                freq[arrivals[i]]++;
            }
        }
        return count;
    }
};