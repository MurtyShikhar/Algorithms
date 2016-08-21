// awesome dp + djikstra's algorithm problem
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <queue>

using namespace std;
class DoubleWeights{
public:
	int minimalCost(vector<string>& weight1, vector<string>& weight2) {
		const int MAX_WEIGHT = 180;
		const int INF = 1<<29;
        int n = weight1.size();
		vector<vector<tuple<int,int,int> > > graph(n);
		for (int i=0; i < n; i++) {
			for (int j=0; j < n; j++) {
				if (weight1[i][j] != '.'){
					int w1=weight1[i][j]-'0';
					int w2=weight2[i][j]-'0';
					graph[i].push_back(make_tuple(w1, w2, j));
				}
			}
		}

		vector<vector<int> > dist(n, vector<int>(MAX_WEIGHT+1, INF));
		dist[0][0]=0;
		set<tuple<int,int,int> > pq;
		pq.insert(make_tuple(0,0,0));
		while (!pq.empty()) {
			auto it = pq.begin();
			int d, w2, x;
			tie(d, w2, x) = *it;
			pq.erase(it);
			for (int i=0; i < graph[x].size(); i++) {
				int w1, del_w2, j;
				tie(w1, del_w2, j) = graph[x][i];
				int nw2 = w2 + del_w2;
				if (nw2 <= MAX_WEIGHT && d + w1 < dist[j][nw2]) {
					//relax
					auto it = pq.find(make_tuple(dist[j][nw2], nw2, j));
					if (it != pq.end())
						pq.erase(it);

					pq.insert(make_tuple(d+w1, nw2, j));
					dist[j][nw2] = d+w1;
				}
			}
		}

		int ans = INF;
		for (int w2=0; w2 <= MAX_WEIGHT; w2++)
			if (dist[1][w2] < INF)
				ans = min(ans, dist[1][w2]*w2);

		return (ans == INF) ? -1 : ans;

	}
};