#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
// atleast one prime number of goals ... 1- none
// 14 -> 1 - (2,3,5,7,11,13)
class PrimeSoccer{
public:

	double getProbability(int skillOfTeamA, int skillOfTeamB){
		double probA = skillOfTeamA/100.0;
		double probB = skillOfTeamB/100.0;

		vector<vector<int> > choose(19, vector<int>(19,0));
		choose[1][0]=choose[1][1]=1;
		for (int i=2; i <= 18; i++) {
			choose[i][0] = 1;
			for (int j=1; j < i; j++) {
				choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
			}

			choose[i][i] = 1;
		}


		double a1 = 0.0;
		double a2 = 0.0;
		for (int i=0; i <= 18; i++) {
			if (i == 2 || i == 3 || i == 5 || i==7 || i==11 || i==13 || i==17) {
				a1 += choose[18][i]*pow(probA, i)*pow(1.0-probA, 18-i);
				a2 += choose[18][i]*pow(probB, i)*pow(1.0-probB, 18-i);
			}

		}

		return 1.0 - (1.0- a1)*(1.0-a2);
	}
};


int main() {
	int a, b;
	cin >> a >> b;
	PrimeSoccer obj;
	double ans = obj.getProbability(a,b);
}