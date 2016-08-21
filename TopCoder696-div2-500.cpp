#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Arrfix{
public:
	int mindiff(vector<int>& A, vector<int>& B, vector<int>& F) {
		int m = A.size();
		int n = F.size();
		multiset<int> st;
		vector<int> used(m,0);
        for (int i=0; i < n; i++)
            st.insert(F[i]);

		// first put stickers where diff and sticker available
		for (int i=0; i < m && n; i++) {
			if (A[i] != B[i]) {
                multiset<int>::iterator itr = st.find(B[i]);
				if (itr != st.end()) {
					st.erase(itr);
					A[i]=B[i];
					used[i]=1;
                    n--;
				}
			}
		}

		// then put stickers where no diff and stickers available
		for (int i=0; i < m && n; i++) {
			if (A[i]==B[i] && !used[i]) {
                multiset<int>::iterator itr = st.find(B[i]);
				if (itr != st.end()) {
					st.erase(itr);
					used[i]=1;
                    n--;
				}
			}
		}

		// then put stickers where diff and no sticker available
		for (int i=0; i < m && n; i++) {
			if (A[i] != B[i] && !used[i]) {
				A[i] = *st.begin();
				st.erase(st.begin());
				used[i]=1;
                n--;
			}
		}

		// last put stickers where no diff and no sticker available
		for (int i=0; i < m && n; i++) {
			if (A[i]==B[i] && !used[i]) {
				A[i] = *st.begin();
				st.erase(st.begin());
				used[i]=1;
                n--;
			}
		}

		int total=0;
		for (int i=0; i < m; i++) {
			if (A[i] != B[i]) total++;
		}

		return total;
	} 
};

