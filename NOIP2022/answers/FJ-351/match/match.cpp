#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;
const LL N = 250010;

LL n, q;
LL a[N], b[N];
LL f1[N][30], f2[N][30];
LL l, r;
LL res;

void init()
{
	for (LL i = 1; i <= n; i ++ )
	{
		f1[i][0] = a[i];
		f2[i][0] = b[i];
	}
	for (LL j = 1; j <= 25; j ++ )
		for (LL i = 1; i + (1 << j) - 1 <= n; i ++ )
		{
			f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
			f2[i][j] = max(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
		}
}

LL query(LL op, LL l, LL r)
{
	LL k = log(r - l + 1) / log(2);
	if (op == 1) return max(f1[l][k], f1[r - (1 << k) + 1][k]);
	return max(f2[l][k], f2[r - (1 << k) + 1][k]);
}

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	LL T;
	scanf("%llu%llu", &T, &n);
	for (LL i = 1; i <= n; i ++ ) scanf("%llu", &a[i]);
	for (LL i = 1; i <= n; i ++ ) scanf("%llu", &b[i]);
	init();
	scanf("%llu", &q);
	while (q -- )
	{
		scanf("%llu%llu", &l, &r);
		LL res = 0;
		for (LL i = l; i <= r; i ++ )
			for (LL j = i; j <= r; j ++ )
				res += query(1, i, j) * query(2, i, j);
		printf("%llu\n", res);
	}
	return 0;
}
