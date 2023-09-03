#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int n, m;

signed main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	cin >> n >> m;
	int s = n + 1;
	int mul = n;
	for (int i = 2; i < n; i++)
		mul *= (n - i + 1), mul /= i, s += mul % MOD;
	for (int i = n - 1; i < m; i++)
		s = (2 * s % MOD + 1) % MOD;
	cout << s % MOD;
	return 0;
}

