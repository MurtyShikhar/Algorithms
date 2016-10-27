#include <set>
#include <vector>

using namespace std;

/* Find max sum subrectangle in a matrix with sum atmost k
   - Break down problem into finding max sum subarray with sum atmost k
 */

class Solution {
public:
   /* time complexity: O(nlogn) */
    int getLargestSumCloseToK(vector<int>& arr, int k) {
        /* sum of a subarray = sum[j] - sum[i-1] <= k but largest... sum[i-1] >= sum[j] - k */
        set<int> nums;
        int sum=0;
        nums.insert(sum);
        int i=0;
        int n=arr.size();
        int ans = -(1<<20);
        while (i < n) {
            sum += arr[i]; // sum = sum of all numbers from 0 to i 
            // nums contains sum of all numbers from 0 to j for all j < i
            auto it = nums.lower_bound(sum - k);
            if (it != nums.end())
                ans = max(ans, sum - (*it));
            nums.insert(sum);
            i++;
        }
        
        assert(ans <= k);
        return ans;
        
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > aux(m, vector<int>(n,0));
        for (int i=0; i<m; i++) {
            aux[i][0] = matrix[i][0];
            for (int j=1; j < n; j++)
                aux[i][j] = aux[i][j-1] + matrix[i][j];
        }
        
        int ans = -(1<<20);
        for (int c1=0; c1 < n; c1++) {
            for (int c2 = c1; c2 < n; c2++) {
                vector<int> mat;
                for (int i=0; i < m; i++){
                    if (c1==0)
                        mat.push_back(aux[i][c2]);
                    else
                        mat.push_back(aux[i][c2] - aux[i][c1-1]);
                }
                
                ans = max(ans, getLargestSumCloseToK(mat, k));
            }    
        }
        
        return ans;
    }
};