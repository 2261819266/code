#include <bits/stdc++.h>
using namespace std;
unsigned long long T, n, q, l, r, sta[300030][30], stb[300030][30], ans;
unsigned long long querya(unsigned long long l, unsigned long long r)
{
	long long k = log2(r - l + 1);
	return max(sta[l][k], sta[r - (1 << k) + 1][k]);
}
unsigned long long queryb(unsigned long long l, unsigned long long r)
{
	long long k = log2(r - l + 1);
	return max(stb[l][k], stb[r - (1 << k) + 1][k]);
}
int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%llu %llu", &T, &n);
	for(unsigned long long i = 1; i <= n; ++i)
		scanf("%llu", &sta[i][0]);
	for(unsigned long long i = 1; i <= n; ++i)
		scanf("%llu", &stb[i][0]);
	for(unsigned long long j = 1; j <= 29; ++j)
		for(unsigned long long i = 1; i + (1 << (j - 1)) <= n; ++i)
		{
			sta[i][j] = max(sta[i][j - 1], sta[i + (1 << (j - 1))][j - 1]);
			stb[i][j] = max(stb[i][j - 1], stb[i + (1 << (j - 1))][j - 1]);
		}
	scanf("%llu", &q);
	while(q--)
	{
		ans = 0;
		scanf("%llu %llu", &l, &r);
		for(unsigned long long L = l; L <= r; ++L)
			for(unsigned long long R = L; R <= r; ++R)
				ans += querya(L, R) * queryb(L, R);
		printf("%llu\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
