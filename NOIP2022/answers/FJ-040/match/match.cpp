#include <bits/stdc++.h>

long long t, n, l, r, q, i, j, k, a[40], b[40], st[6][40];
unsigned long long ans, maxa, maxb;

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);

	scanf("%lld%lld", &t, &n);
	
	for (i = 1; i <= n; i++)
		scanf("%lld", a + i);
	
	for (i = 1; i <= n; i++)
		scanf("%lld", b + i);	

	scanf("%lld", &q);
			
	
	while (q--)
	{
		ans = 0;
		
		scanf("%lld%lld", &l, &r);
		
		for (i = l; i <= r; i++)
			for (j = i; j <= r; j++)
			{
				maxa = maxb = 0;
				
				for (k = i; k <= j; k++)
					maxa = std::max((long long)maxa, a[k]),
					maxb = std::max((long long)maxb, b[k]);
				
				ans += maxa * maxb;		
			}
		
		printf("%llu\n", ans);
	}
}

