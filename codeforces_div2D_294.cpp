#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdio>

using namespace std;
/* 
	interesting problem! 
	the key idea is the following: 
	given a char, consider all the idxs where this char appears.
	we need to find idx1 and idx2 such that sum[idx2-1] = sum[idx1]. doing this naively would be O(N^2).
	but we can use a hashtable and store for each char, for each id, the sum at that id!!
*/
void solve(string& s, vector<int>& scores) {
	vector<vector<int> > idx(26);
	int n=s.size();
	vector<long long> cumulatives(n, 0);
	cumulatives[0]=scores[s[0]-'a'];

	for (int i=0; i< n; i++){
		idx[s[i]-'a'].push_back(i);
		cumulatives[i] = cumulatives[i-1] + scores[s[i]-'a'];
	}

	long long ans=0;
	for (int i=0; i < 26; i++) {
		unordered_map<long long, int> m; // number of idxs with a given sum[idx]
		for (int j=0; j < idx[i].size(); j++) {
			int currIdx = idx[i][j]; 
			/* if currIdx is the second endpoint of an interesting substring 
				the first endpoint is such that its score is cumulatives[currIdx-1]. Use a map to store all
				such first endpoints!
			 */
			if (currIdx!=0) 
				ans += m[cumulatives[currIdx-1]];
			m[cumulatives[currIdx]]++;

		}
	}

	cout << ans << "\n";
}

int main()
{
	
	vector<int> scores(26,0);
	for (int i=0; i < 25; i++)
		scanf("%d ", &scores[i]);
	scanf("%d\n", &scores[25]);

	string s;
	getline(cin, s);

	solve(s, scores);
	return 0;
}