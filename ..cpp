#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int f(string x, string y) {
	int m = x.size();
	int n = y.size();
	vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				v[i][j] = v[i - 1][j - 1] + 1;
			} else {
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
		}
	}
	return v[m][n];
}
bool g(string x, string y) {
	if (x.size() != y.size()) {
		return false;
	}
	return f(x + x, y) == y.size();
}
int main() {
	string x, y;
	cin >> x >> y;
	cout << g(x, y) << endl;
	return 0;
}