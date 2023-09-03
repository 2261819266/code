// 我看到样例 3 的震惊超过了我两年前看到了 Julian 的震惊 

#include <bits/stdc++.h>
#define reg register

const int N = 1010, P = 998244353;

int T, id, n, m, c, f, C, F, num[N][N], sum[N][N], num2[N][N]; // num: how much 0 after it, sum: the sum of num[][] from it to the last 0 bellow it
char str[N][N];

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	scanf("%d %d", &T, &id);
	while (T -- )
	{
		C = 0; F = 0;
		memset(num, 0, sizeof num); memset(sum, 0, sizeof sum); memset(num2, 0, sizeof num2);
		
		scanf("%d %d %d %d", &n, &m, &c, &f);
		for (reg int i = 1; i <= n; ++ i) scanf("%s", str[i] + 1);
		if (c == 0 && f == 0) { printf("0 0\n"); continue; }
		
		for (reg int i = 1; i <= n; ++ i) for (reg int j = m - 1; j; -- j) if (str[i][j + 1] == '0') num[i][j] = num[i][j + 1] + 1;
		for (reg int j = 1; j <= m; ++ j) for (reg int i = n - 1; i; -- i) if (str[i + 1][j] == '0') num2[i][j] = num2[i + 1][j] + 1;
		for (reg int j = 1; j <= m; ++ j)
		{
			if (str[1][j] == '0') sum[1][j] = num[1][j];
			for (reg int i = 2; i <= n; ++ i) sum[i][j] = num[i][j] + (str[i - 1][j] == '0') * sum[i - 1][j];
		}
		for (reg int i = 3; i <= n; ++ i)
			for (reg int j = 1; j <= m - 1; ++ j)
				if (str[i][j] == '0' && str[i - 1][j] == '0' && str[i - 2][j] == '0')
					C = (C + 1ll * sum[i - 2][j] * num[i][j]) % P,
					F = (F + 1ll * sum[i - 2][j] * num[i][j] % P * num2[i][j] % P) % P;
		printf("%d %d\n", (C * c + P) % P, (F * f + P) % P);
	}
}

