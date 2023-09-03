#include <bits/stdc++.h>
using namespace std;

#define N 100005
int T, n, q;
long long a[N], b[N];
long long sta[N][31], stb[N][31];
unsigned long long ans;
//#define mod 

long long querya(int i, int j) {
	if(i == j) return a[i];
	int len = j - i ;
	int asd = log2(len);
	return max(sta[i][asd], sta[j - (1 << asd)][asd]);
}
long long queryb(int i, int j) {
	if(i == j) return b[i];
	int len = j - i;
	int asd = log2(len);
	return max(stb[i][asd], stb[j - (1 << asd)][asd]);
}

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d %d", &T, &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++ i) scanf("%d", b + i);
	for (int i = n - 1; i >= 1; -- i) sta[i][0] = max(a[i], a[i + 1]);	
	for (int i = n - 1; i >= 1; -- i) stb[i][0] = max(b[i], b[i + 1]);
	scanf("%d", &q);
	for (int i = 1; i <= 21; ++ i)
		for (int j = 1; j + (1 << i) <= n; ++ j) {
			sta[j][i] = max(sta[j][i - 1], sta[j + (1 << (i - 1))][i - 1]); 
			stb[j][i] = max(stb[j][i - 1], stb[j + (1 << (i - 1))][i - 1]); 
		} 
//	for (int i = 1; i <= n; ++ i) {
//		for (int j = 0; j <= m; ++ j) {
//			cout << sta[i][j] << " ";
//		}
//		puts("");
//	}
	while(q --) {
 		int l, r;
		ans = 0;
		scanf("%d %d", &l, &r);
		for (int i = l; i <= r; ++ i) {
			for (int j = i; j <= r; ++ j) {
				long long y = querya(i, j);
				long long x = queryb(i, j);
				ans += x * y;
			}
		}
		printf("%lld\n", ans);
	}
}
/*
0 30
9 30 25 18 7 3 29 15 12 16 14 26 24 5 1 8 13 28 6 17 2 22 4 23 27 10 11 19 20 21
27 24 11 26 7 3 8 15 25 10 1 4 18 14 20 23 9 22 29 30 13 28 19 17 2 21 6 12 5 16
30
1 30
1 30
6 30
3 26
4 26
6 28
1 24
4 30
7 29
3 24
7 30
3 26
4 26
2 29
4 30
6 21
8 29
11 14
15 19
19 20
7 30
25 30
7 9
19 30
7 26
13 26
5 30
15 24
18 21
23 29

//330691
//330691
//221025
//204369
//186165
//186614
//205881
//260314
//185960
//167988
//202688
//204369
//186165
//284800
//260314
//81059
//168502
//3028
//7045
//1194
//202688
//7036
//2292
//43386
//138979
//68281
//239451
//34587
//5348
//11096

*/
