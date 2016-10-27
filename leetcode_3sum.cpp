#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int> > ret;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i=0; i < n; i++) {
            if (i == 0 || arr[i] != arr[i-1]){
            int l= i+1;
            int r = n-1;
            int target = -arr[i];
            while (l < r) {
                int currSum = arr[l] + arr[r];
                if (currSum == target) {
                    vector<int> triple; triple.push_back(arr[i]); triple.push_back(arr[l]); triple.push_back(arr[r]);
                    ret.push_back(triple);
                    l++;
                    r--;
                    while (l < r && arr[r] == arr[r+1]) r--;
                    while (l < r && arr[l] == arr[l-1]) l++;
                }
                else if (currSum > target)
                    r--;
                else
                    l++;
            }
            }
            
        }
        
        //vector<vector<int> > ret_vec(ret.begin(), ret.end());
        return ret;
        
        
    }
};