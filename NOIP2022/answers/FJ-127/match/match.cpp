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

const int N = 2.5e5 + 10;
int n, a[N], b[N], pos[N];
unsigned long long fa[3010][3010];
int S[N];

inline void Add(int x)
{
	for (; x <= n; x += (x) & (-x))
		S[x] += 1;
}

inline int query(int x)
{
	int sum = 0;
	for (; x; x -= (x) & (-x))
		sum += S[x]; 
	return sum;
}


inline int queryR(int s, int e)
{
	int l = s, r = e, ans = -1;
	while (r >= l)
	{
		int mid = (l + r) / 2;
		if (query(mid) - query(s - 1) == 0)
		{
			ans = mid;
			l = mid + 1;
		} 
		else r = mid - 1;
	} 
	return ans;
}

inline int queryL(int s, int e)
{
	int l = s, r = e, ans = -1;
	while (r >= l)
	{
		int mid = (l + r) / 2;
		if (query(e) - query(mid - 1) == 0)
		{
			ans = mid;
			r = mid - 1;
		} 
		else l = mid + 1;
	} 
	return ans;
}

int main()
{
	freopen("match.in", "r", stdin); 
	freopen("match.out", "w", stdout); 
	int T;
	read(T), read(n);
	for (int i = 1; i <= n; ++ i)
		read(a[i]);
	for (int i = 1; i <= n; ++ i)
		read(b[i]), pos[b[i]] = i;

	if (T <= 5)
	{
		for (int i = 1; i <= n; ++ i)
			for (int j = i; j <= n; ++ j)
				fa[i][j] = std::max(fa[i][j - 1], (unsigned long long)a[j]);

		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				fa[i][j] += fa[i][j - 1] + fa[i - 1][j] - fa[i - 1][j - 1];

		int Q; read(Q);
		for (int i = 1; i <= Q; ++ i)
		{
			unsigned long long ans = 0;
			int l, r; read(l), read(r);
			for (int j = 1; j <= n; ++ j)
				S[j] = 0;
			for (int j = n; j >= 1; -- j)
			{
				if (pos[j] > r || pos[j] < l) continue;
				int R = queryR(pos[j], r);
				int L = queryL(l, pos[j]);
				ans += (fa[pos[j]][R] - fa[pos[j]][pos[j] - 1] - fa[L - 1][R] + fa[L - 1][pos[j] - 1]) * j;
				Add(pos[j]); 
			}
			std::cout << ans << '\n'; 
		}
	}
	return 0;
}
