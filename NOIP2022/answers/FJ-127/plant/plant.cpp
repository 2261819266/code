#include <bits/stdc++.h>

template < typename T >
inline void read(T &cnt)
{
	cnt = 0; char ch = getchar(); bool op = 1;
	for (; ! isdigit(ch); ch = getchar())
		if (ch == '-') op = 0;
	for (; isdigit(ch); ch = getchar())
		cnt = cnt * 10 + ch - 48;
	cnt = op ? cnt : -cnt;
} 

const int N = 1e3 + 10; 
const int mod = 998244353;

int n, m, c, f;
char s[N][N];
int a[N][N], expand_r[N][N];
inline void solve()
{
	read(n), read(m), read(c), read(f);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; ++ j)
			a[i][j] = s[i][j] - '0'; 
	} 
	for (int j = m; j >= 1; -- j)
	{
		for (int i = 1; i <= n; ++ i)
		{
			if (a[i][j] == 1) expand_r[i][j] = 0; 
			else expand_r[i][j] = expand_r[i][j + 1] + 1;
		}
	} 
	long long Vc = 0, Vf = 0; 
	for (int j = 1; j <= m; ++ j)
	{
		long long sum = 0, pre = 0;
		for (int i = n; i >= 1; -- i)
		{
			if (expand_r[i][j] == 0) 
			{
				sum = 0; pre = 0;
				continue;
			}
			long long multi = sum;
			Vc = (Vc + (multi - pre) * (expand_r[i][j] - 1) % mod) % mod;
			pre = (expand_r[i][j] - 1) % mod;
			sum = (sum + expand_r[i][j] - 1) % mod;
		}
	}


	for (int j = 1; j <= m; ++ j)
	{
		long long multiS = 0, sum = 0, pre = 0;
		for (int i = n; i >= 1; -- i)
		{
			if (expand_r[i][j] == 0)
			{
				multiS = 0, sum = 0, pre = 0;
				continue;
			}
			long long multi = multiS;
			Vf = (Vf + (multi - pre) * (expand_r[i][j] - 1) % mod) % mod;
			multiS = (multiS + sum * (expand_r[i][j] - 1) % mod) % mod;
			pre = sum * (expand_r[i][j] - 1) % mod; sum ++;
		}
	}
	
	std::cout << Vc * c % mod << ' ' << Vf * f % mod << '\n';
}

int main()
{
	freopen("plant.in", "r", stdin); 
	freopen("plant.out", "w", stdout); 
	int T, id; 
	read(T), read(id);
	while (T --) solve();
	return 0;
}
