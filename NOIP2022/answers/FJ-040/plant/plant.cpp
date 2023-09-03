#include <bits/stdc++.h>
#define mod 998244353

long long t, id, n, m, c, f, i, j, k, down, ans1, ans2, pos[1001], sum[1001], line[1001];
char a[1001][1001];

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);

	scanf("%lld%lld", &t, &id);
	
	while (t--)
	{
		scanf("%lld%lld%lld%lld", &n, &m, &c, &f);
		
		ans1 = ans1 = 0;
		memset(pos, 0, sizeof pos);
		
		for (i = 1; i <= n; i++)
			scanf("%s", a[i] + 1);
			
		for (i = 1; i <= m; i++)
		{
			memset(sum, 0, sizeof sum);
			memset(line, 0, sizeof line);
			down = 0;
			
			for (j = 1; j <= n; j++)
				if (i > pos[j])
				{
					for (k = i; k <= m && a[j][k] != '1'; k++);
					pos[j] = k - 1;
				}
			
			for (j = 1; j <= n; j++)
				if (pos[j] - i >= 0)
					sum[j] = sum[j - 1] + (pos[j] - i),
					line[j] = line[j - 1] + 1;
			
			for (j = n; j; j--)
			{
				if (pos[j] - i > 0 && line[j] > 2)
				{
					ans1 = (ans1 + (pos[j] - i) * sum[j - 2]) % mod;
					ans2 = (ans2 + (pos[j] - i) * sum[j - 2] * down) % mod;
				}	
				
				pos[j] - i >= 0 ? down++ : (down = 0);	
			}
		}
			
		printf("%lld %lld\n", ans1 * c, ans2 * f);
	}
}

