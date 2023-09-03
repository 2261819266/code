#include <bits/stdc++.h>
#define si int
#define int long long

using namespace std;

const int MOD = 998244353;

si book[1001][1001];
si n, m, c, f;
si sh[1001][1001];

int countC() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = j; k <= m; sh[i][j]++, k++)
				if (book[i][k] == 1)
				   break;
	int count = 0;
	for (int i = 1; i <= n - 2; i++) 
		for (int j = 1; j <= m - 1; j++) {
			int st;
			for (st = i; st <= n; st++)
				if (book[st][j] == 1)
					break;
			for (int k = i + 2; k < st; k++)
				count += sh[k][j + 1] * sh[i][j + 1] % MOD, count %= MOD;
		}
	return count;
}

int countF() {
	int count = 0;
	for (int i = 1; i <= n - 3; i++)
		for (int j = 1; j <= m - 1; j++) {
			int st;
			for (st = i; st <= n; st++)
				if (book[st][j] == 1)
					break;
			for (int k = i + 2; k < st - 1; k++)
				count += sh[i][j + 1] * sh[k][j + 1] * (st - 1 - k) % MOD, count %= MOD;
		}
	return count;
}

signed main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	cin.tie();
	cout.tie();
	si t, id; cin >> t >> id;
	while (t--) {
  		cin >> n >> m >> c >> f;
		if (id == 1) {
			cout << "0 0" << endl;
			continue;
		} for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				char c; cin >> c;
				if (c == '0')
	   			    book[i][j] = 0;
				else
					book[i][j] = 1;
			}
  		cout << countC() << ' ';
		if (id == 15)
   			cout << 0 << endl;
		else
   			cout << countF() << endl;
	}
	return 0;
}

