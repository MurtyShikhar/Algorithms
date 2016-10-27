#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& arr) {
    	int n = arr.size();
    	int i=0;
    	long ans = 0;
    	while (i < n) {
    		long curr=1;
    		if (i > 0 && arr[i] > arr[i-1]) curr++;
    		while (i < n-1 && arr[i] < arr[i+1]) {ans += curr; i++; curr++;}
    		long curr2=1;
    		while (i < n-1 && arr[i] > arr[i+1]) {ans+= curr2; i++; curr2++;}
    		ans += max(curr, curr2);
    		i++;
    	}

    	return ans;
    }
};