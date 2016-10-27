#include <algorithm>

/* O(n^2) optimization */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        vector<pair<int,int> > numsIdx(n);
        for (int i=0; i < n; i++)
            numsIdx[i] = make_pair(nums[i], i);
            
        sort(numsIdx.begin(), numsIdx.end());
        
        for (int i=0; i < n; i++) {
            int j = i+1;
            while (j < n) {
                long score1 = abs(long(numsIdx[i].first) - long(numsIdx[j].first));
                long score2 = abs(numsIdx[i].second - numsIdx[j].second);
                if (score1 <= t && score2 <= k)
                    return true;
                else{
                    if (score1 > t)
                        break;
                    else
                        j+=1;
                    
                }
            }
        }
        
        return false;
    }
};