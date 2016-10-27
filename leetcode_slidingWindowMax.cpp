#include <deque>

using namespace std;
// deque invariant:
// all elements are in the current window and arranged in descending order of values AND increasing
// order of index
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        /* use a deque since sliding window requires enqueing from one end, and dequeuing from another */
        deque<int> aux;
        int i=0;
        int sz=A.size();
        vector<int> ans;
        while (i < k) {
            /* remove all elements in deque that are smaller than current element */
            // if A[i] is greater than q.front() note that in any window that has q.front(), it will always have
            // A[i] since they are less than k distance apart, and hence q.front() is useless since A[i] is greater
            // so we remove all such elements.
            while (!aux.empty() && A[i] >= A[aux.front()]) aux.pop_front();
            aux.push_front(i);
            i++;
        }
        /* all elements in deck are sorted with aux.back() being the largest. Also all are in range 0..k-1 */
        if (!aux.empty())
            ans.push_back(A[aux.back()]);
        // i = k
        while (i < sz) {
            while (!aux.empty()  && aux.back() <= i -k) aux.pop_back(); // remove all elements not in range
            while (!aux.empty() && A[i] >= A[aux.front()]) aux.pop_front();
            /* all elements in deque are now in range (i-k+1...i) */
            aux.push_front(i);
            ans.push_back(A[aux.back()]); // max in (i-k+1...i)
            i++;
        }

        return ans;
    }
};