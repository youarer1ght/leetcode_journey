#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> cnt;    // num, i+1
        int n = cards.size();
        int minCard = n + 1;
        for(int i = 0; i < cards.size(); i++){
            if(cnt[cards[i]] > 0){
                minCard = min(minCard, i - cnt[cards[i]] + 2);
            }
            cnt[cards[i]] = i + 1;
        }
        return minCard > n ? -1 : minCard;
    }
};