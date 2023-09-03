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

const int S = 2e6 + 10;
const int N = 300 + 10;

int n, m, k;
int a[S];

struct oup 
{
	int op, x, y;
} answer[2 * S];

namespace subtask_1To3
{ 
	int sta[N][2];
	inline void solve()
	{
		int cnt = 0;
		for (int i = 1; i <= m; ++ i)
		{
			int x = (a[i] + 1) / 2;
			if (sta[x][0] == a[i])
			{
				++ cnt; answer[cnt] = {1, n};
				++ cnt; answer[cnt] = {2, x, n};
				sta[x][0] = sta[x][1]; sta[x][1] = 0;
			}
			else if (sta[x][1] == a[i])
			{
				++ cnt; answer[cnt] = {1, x};
				sta[x][1] = 0;
			}
			else 
			{
				++ cnt; answer[cnt] = {1, x};
				if (sta[x][0]) sta[x][1] = a[i];
				else sta[x][0] = a[i];
			}
		}

		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; ++ i)
		{
			printf("%d %d", answer[i].op, answer[i].x);
			if (answer[i].op == 2) printf(" %d\n", answer[i].y);
			else printf("\n"); 
		}
	}
}

namespace subtask_4To6
{
	int st[S], pos, cnt1[N], cnt;
	inline void solve()
	{
		int dot = 0;
		for (int i = m; i >= 1; -- i)
		{
			cnt1[a[i]] = 1;
			if (cnt1[1] + cnt1[2] + cnt1[3] == 2)
			{
				if (cnt1[1] == 0) dot = 1;
				if (cnt1[2] == 0) dot = 2;
				if (cnt1[3] == 0) dot = 3;
				break;
			}
		} 
		int suf = 0;
		for (int i = m; i >= 1; -- i)
			if (a[i] == dot)
			{
				suf = i;
				break;
			}
	
		for (int i = 1; i <= suf; ++ i)
		{
			if (a[i] == dot)
			{
				++ cnt; answer[cnt] = {1, 1};
			}
			else 
			{
				++ cnt; answer[cnt] = {1, 2};
				pos ++; st[pos] = a[i];
			}
		}
		for (int i = suf + 1; i <= m; ++ i)
		{
			if (st[pos] == a[i])
			{
				++ cnt; answer[cnt] = {1, 2};
				pos --;
			}
			else
			{
				++ cnt; answer[cnt] = {1, 1};
				++ cnt; answer[cnt] = {2, 1, 2};
			}
		}

		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; ++ i)
		{
			printf("%d %d", answer[i].op, answer[i].x);
			if (answer[i].op == 2) printf(" %d\n", answer[i].y);
			else printf("\n"); 
		}
	}
}


namespace lst
{
	int st[5][S], pos[N], cnt1[N], cnt;
	inline void solve()
	{
		int dot = 0, sum = 0;
		for (int i = m; i >= 1; -- i)
		{
			if (cnt1[a[i]] == 0) sum ++;
			cnt1[a[i]] = 1;
			if (sum == n - 1)
			{
				for (int j = 1; j <= n; ++ j)
					if (cnt1[a[j]] == 0) dot = j;
				break;
			}
		} 
		int suf = 0;
		for (int i = m; i >= 1; -- i)
			if (a[i] == dot)
			{
				suf = i;
				break;
			}
	
		for (int i = 1; i <= suf; ++ i)
		{
			int x = (a[i] + 1) / 2;
			if (a[i] == dot)
			{
				++ cnt; answer[cnt] = {1, n};
			}
			else 
			{
				++ cnt; answer[cnt] = {1, x};
				pos[x] ++; st[x][pos[x]] = a[i];
			}
		}
		for (int i = suf + 1; i <= m; ++ i)
		{
			int x = (a[i] + 1) / 2;
			if (st[x][pos[x]] == a[i])
			{
				++ cnt; answer[cnt] = {1, x};
				pos[x] --;
			}
			else
			{
				++ cnt; answer[cnt] = {1, n};
				++ cnt; answer[cnt] = {2, n, x};
			}
		}

		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; ++ i)
		{
			printf("%d %d", answer[i].op, answer[i].x);
			if (answer[i].op == 2) printf(" %d\n", answer[i].y);
			else printf("\n"); 
		}
	}
}

inline void solve()
{
	read(n), read(m), read(k);
	for (int i = 1; i <= m; ++ i)
		read(a[i]); 
	if (k == 2 * n - 2)
	{
		subtask_1To3::solve();
	}
	if (n == 2 && k == 2 * n - 1)
	{
		subtask_4To6::solve();
		return; 
	}
	lst::solve();
}

int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T; read(T);
	while (T --) solve();
	return 0;
} 
