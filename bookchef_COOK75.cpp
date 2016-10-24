#include <vector>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;


int main() {
	int n, m; scanf("%d %d\n", &n, &m);
	int idx;
	unordered_set<int> special;
	for (int i=0; i < n-1; i++) {
		scanf("%d", &idx);
		special.insert(idx);
	}

	scanf("%d\n", &idx);
	special.insert(idx);

	vector<pair<int, string> > specials;
	vector<pair<int, string> > nonSpecial;
	stringstream ss;
	string s;
	for (int i =0; i < m; i++) {
		getline(cin, s);
		ss.clear();
		ss << s;
		string t;
		int k=0;
		int pop, idx;
		string message;
		while (ss >> t) {
			if (k < 2){
				if (k==0)
					idx = stoi(t);
				else
					pop = stoi(t);
			}

			else {
				message = t;
			}

			k+=1;
		}

		auto it = special.find(idx);
		if (it != special.end())
			specials.push_back(make_pair(pop, message));
		else
			nonSpecial.push_back(make_pair(pop, message));
	}

	sort(specials.begin(), specials.end());
	sort(nonSpecial.begin(), nonSpecial.end());
	for (int i=specials.size()-1; i >=0; i--) {
		cout << specials[i].second << "\n";
	}
	for (int i=nonSpecial.size()-1; i >=0; i--) {
		cout << nonSpecial[i].second << "\n";
	}

}