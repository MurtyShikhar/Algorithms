#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& a, int target, int lo, int hi) {
        int n = a.size();

        while (lo <= hi) {
            int mid = (lo + (hi-lo)/2);
            if (a[mid]==target)
                return mid;
            else if (a[mid] > target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        
        
        return -1;
        
    }
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int i=0;
        for (; i < n-1; i++) {
            if (nums[i] > nums[i+1])
                break;
        }
        
        int t1 =  binarySearch(nums, target, 0, i);
        int t2 = binarySearch(nums, target, i+1, n-1);
        if (t1==-1)
            return t2;
        else
            return t1;
        
    }
};