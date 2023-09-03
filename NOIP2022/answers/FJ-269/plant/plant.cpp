#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
long long T, id, n, m, c, f, num[1010][1010], cnt[1010][1010], ansc, ansf, tmp;
char s[1010][1010];
int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%lld %lld", &T, &id);
	while(T--)
	{
		memset(num, 0, sizeof(num));
		memset(cnt, 0, sizeof(cnt));
		ansc = ansf = 0;
		scanf("%lld %lld %lld %lld", &n, &m, &c, &f);
		for(long long i = 1; i <= n; ++i)
			scanf("%s", s[i] + 1);
		for(long long i = 1; i <= n; ++i)
			for(long long j = 1; j <= m; ++j)
				num[i][j] = s[i][j] - '0';
		for(long long i = 1; i <= n; ++i)
			for(long long j = m - 1; j >= 1; --j)
				if(!num[i][j] && !num[i][j + 1])
					cnt[i][j] = cnt[i][j + 1] + 1;
		for(long long i = 3; i <= n; ++i)
			for(long long j = 1; j <= m; ++j)
			{
				long long now = i;
				tmp = 0;
				while(now - 1 >= 1 && !num[now - 1][j])
				{
					--now;
					if(i - now > 1)
					{
						ansc = (ansc + cnt[i][j] * cnt[now][j]) % mod;
						tmp = (tmp + cnt[i][j] * cnt[now][j]) % mod;
					}
				}
				long long now2 = i;
				while(now2 + 1 <= n && (!num[now2 + 1][j]))
					++now2;
				ansf = (ansf + tmp * (now2 - i) % mod) % mod;
			}
		
		printf("%lld %lld\n", c * ansc % mod , f  * ansf % mod);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
