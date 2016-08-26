#include <vector>
#include <iostream>

using namespace std;
hn
class ChooseTheBestOne{
public:
	int countNumber(int N){
		vector<int> tshirts(N);
		for (int i=0; i < N; i++)
			tshirts[i]=i+1;

		int start=0;
		for (int t=1; t < N; t++) {
			long long countTill = t*t*t;
			int sz = tshirts.size();
			int idxToRemove = (start+countTill)%sz;
			if (idxToRemove == 0)
				idxToRemove = sz-1;
			else
				idxToRemove--;

			tshirts.erase(tshirts.begin() + idxToRemove);
			start = idxToRemove;
		}

		return tshirts[0];
	}
};

int main() {
	int N; cin >> N;
	ChooseTheBestOne obj;
	int ans = obj.countNumber(N);
	cout << ans << "\n";
}