#include <vector>
#include <iostream>
#include <map>
#define mp make_pair 

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<pair<int, pair<int,int> >, double> memo;
class FoxAndTouristFamilies{
public:
	
	double dfs(vvi& graph, int i, int parent, int family, memo& m) {
		double ans = 1.0;
		for (int j=0; j < graph[i].size(); j++) {
			int child = graph[i][j];
			if (child != parent) {
				int curr = dfs(graph, child, i, family, m);
				ans += curr;
			}
		}

		if (i > parent)
			m.insert(mp( mp(family, mp(i, parent)), ans));
		else
			m.insert(mp( mp(family, mp(parent, i)), ans));

		return ans;
	}

	double expectedLength(vector<int>& A, vector<int>& B, vector<int>& f){
		int n = A.size()+1;
		int m = f.size();

		vvi graph(n);
		for (int i=0; i < n-1; i++) {
			// A[i]-B[i]
			graph[A[i]].push_back(B[i]);
			graph[B[i]].push_back(A[i]);
		}

		memo table;
		for (int i=0; i < m; i++) {
			dfs(graph, f[i], -1, f[i], table);
		}	

		double ret = 0.0;
		for (int j=0; j < n-1; j++){
			double ans = 1.0;
			pair<int,int> road;
			if (A[j] > B[j])
				road = mp(A[j], B[j]);
			else
				road = mp(B[j], A[j]);
			for (int i=0; i < m; i++) {
				ans *= table[mp(f[i], road)]/(n-1);
			}

			ret += ans;
		}	

		return ret;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<int> A(n-1), B(n-1), C(m);
	for (int i=0; i < n-1; i++) {
		cin >> A[i];
	}
	for (int i=0; i < n-1; i++) {
		cin >> B[i];
	}

	for (int i=0; i < m; i++) {
		cin >> C[i];
	}

	FoxAndTouristFamilies obj;
	double ans = obj.expectedLength(A, B, C);
	cout << ans << "\n";
}

