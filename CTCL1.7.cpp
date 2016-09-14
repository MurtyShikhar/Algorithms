#include <vector>
#include <iostream>

using namespace std;

void setColumnZero(vector<vector<int> >& matrix, int col) {
	int m = matrix.size();
	for (int i=0; i < m; i++)
		matrix[i][col]=0;
}

void setRowZero(vector<vector<int> >& matrix, int row) {
	int n = matrix[0].size();
	for (int i=0; i < n; i++)
		matrix[row][i]=0;
}

void setZeros(vector<vector<int> >& matrix) {
	int m= matrix.size();
	int n = matrix[0].size();

	bool setLast=false;
	for (int i=0; i < n; i++) if (matrix[m-1][i] == 0) setLast=true;

	for (int i=0; i < m-1; i++) {
		bool mark=false;
		for (int j=0; j < n; j++) 
			if (matrix[i][j]==0) {
				mark=true;
				matrix[m-1][j]=0;
			}
		if (mark)
			setRowZero(matrix, i);
	}

	for (int i=0; i < n; i++) {
		if (matrix[m-1][i] == 0)
			setColumnZero(matrix, i);
	}

	if (setLast)
		setRowZero(matrix, m-1);	
}

int main() {
	int m,n;
	cin >> m >> n;
	vector<vector<int> > matrix(m, vector<int>(n,0));
	for (int i=0; i < m; i++)
		for (int j=0; j < n; j++)
			cin >> matrix[i][j];

	setZeros(matrix);
	for (int i=0; i < m; i++){
		for (int j=0; j < n-1; j++)
			cout << matrix[i][j] << " ";
		cout << matrix[i][n-1] << "\n";
	}

}