#include <vector>

using namespace std;

/* very hard problem */
class Solution {
public:

    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long miss=1; // miss is the first number we can't form.. -> we can all numbers from (0, miss-1)
        int sz = nums.size();
        int i=0;
        while (miss <= n) {
            if (i < sz && nums[i] <= miss) {
                miss += nums[i];
                // we could earlier make numbers from (0, miss-1) and now we can make numbers from (0, miss-1+nums[i])
                // basically we can make any number of the form nums[i] + k where k goes from (miss-nums[i]) to nums[i] + miss-1 
                i++;
            }
            
            else {
                miss<<=1; 
                // add miss to the array this means we can form all numbers of the form miss + k where k goes from 0 to miss-1
                patches+=1;
            }
        }
        
        return patches;
        
    }
};