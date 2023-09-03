#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
const int N = 3e3 + 7;

ull valA[N], valB[N];

ull colorful[N][N], sum[N][N];

int T, n, Q;

template<class T>
inline T read() {
	T x = 0;
	char c = getchar();
	
	while (c < '0' || c > '9')
		c = getchar();
	
	while (c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + (c & 15), c = getchar();
	
	return x;
}

signed main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	T = read<int>(), n = read<int>();
	
	for (int i = 1; i <= n; ++i)
		valA[i] = read<ull>();
	
	for (int i = 1; i <= n; ++i)
		valB[i] = read<ull>();
	
	for (int i = 1; i <= n; ++i) {
		ull maxA = 0, maxB = 0;
		
		for (int j = i; j <= n; ++j) {
			maxA = max(maxA, valA[j]), maxB = max(maxB, valB[j]);
			colorful[i][j] = maxA * maxB;
		}
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + colorful[i][j];
	
	Q = read<int>();
	
	for (int l, r; Q; --Q) {
		l = read<int>(), r = read<int>();
		printf("%llu\n", sum[r][r] - sum[l - 1][r] - sum[r][l - 1] + sum[l - 1][l - 1]);
	}
	
	return 0;
}
