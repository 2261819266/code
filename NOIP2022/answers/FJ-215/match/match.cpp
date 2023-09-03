#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
const int MAXN = 3000 + 10;
int T, N, Q;
LL l[MAXN], r[MAXN];
LL val[MAXN][MAXN];
LL sum[MAXN][MAXN]; // 每行的前缀和 
LL a[MAXN], b[MAXN];

void init() {
	for(int p = 1; p <= N; p++) {
		LL mxa = 0, mxb = 0;
		for(int q = p; q <= N; q++) {
			mxa = max(mxa, a[q]);
			mxb = max(mxb, b[q]);
			val[p][q] = mxa * mxb;
		}
	}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			sum[i][j] = sum[i][j - 1] + val[i][j];
}
int main() {
	#ifdef test
		freopen("test.txt", "r", stdin);
	#else
		freopen("match.in", "r", stdin);
		freopen("match.out", "w", stdout);
	#endif
	cin >> T >> N;
	for(int i = 1; i <= N; i++) 
		scanf("%lld", &a[i]);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &b[i]);
	init();
	
	cin >> Q;
	LL x, y;
	for(int i = 1; i <= Q; i++) {
		scanf("%lld %lld", &x, &y);
		unsigned long long ans = 0;
		for(int i = x; i <= y; i++) // Line
			ans += sum[i][y] - sum[i][i - 1];
		printf("%llu\n", ans);
	}
		
	return 0;
}

