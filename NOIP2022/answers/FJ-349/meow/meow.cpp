#include <bits/stdc++.h>
#define reg register

const int N = 2000010;

int n, m, k, a[N], cnt, ans[N]; // 1 : 1 1, 2 : 1 2, 3 : 2 1 2 

struct deq
{
	int h = 1, t, c[N];
	int sz() { return t - h + 1; }
	int push(reg int x) { return c[ ++ t] = x, 1; }
};

namespace Subtask2
{
	deq x, y;
	
	int main()
	{
		for (reg int i = 1; i <= m; ++ i)
		{
			if (x.sz() && a[i] == x.c[x.t]) { -- x.t, ans[ ++ cnt] = 1; continue; }
			if (y.sz() && a[i] == y.c[y.t]) { -- y.t, ans[ ++ cnt] = 2; continue; }
			if (x.sz() && a[i] == x.c[x.h] && !y.sz()) { ++ x.h, ans[ ++ cnt] = 2, ans[ ++ cnt] = 3; continue; }
			if (y.sz() && a[i] == y.c[y.h] && !y.sz()) { ++ y.h, ans[ ++ cnt] = 1, ans[ ++ cnt] = 3; continue; }
			if (a[i] == a[i + 1]) { ans[ ++ cnt] = 1; x.push(a[i]); continue; }
			if (x.sz() == 2) { (a[i + 1] == x.c[x.h]) ? (x.push(a[i]), ans[ ++ cnt] = 1) : (y.push(a[i]), ans[ ++ cnt] = 2); continue; }
			if (y.sz() == 2) { (a[i + 1] == y.c[y.h]) ? (y.push(a[i]), ans[ ++ cnt] = 2) : (x.push(a[i]), ans[ ++ cnt] = 1); continue; }
			if (x.sz() == 1 && y.sz() == 1) { (a[i + 1] == x.c[x.h]) ? (y.push(a[i]), ans[ ++ cnt] = 2) : (x.push(a[i]), ans[ ++ cnt] = 1); continue; }
			ans[ ++ cnt] = 1; x.push(a[i]);
		}
		printf("%d\n", cnt);
		for (reg int i = 1; i <= cnt; ++ i)
			if (ans[i] == 1) printf("1 1\n");
			else if (ans[i] == 2) printf("1 2\n");
			else printf("2 1 2\n");
		return 0;
	}
}

namespace Subtask3
{
	deq x, y, z;
	
	void dfs(reg int dep)
	{
		if (dep == m + 1)
		{
			if (x.sz() == 0 && y.sz() == 0 && z.sz() == 0)
			{
				printf("%d\n", cnt);
				for (reg int i = 1; i <= cnt; ++ i)
					if (ans[i] == 1) printf("1 1\n");
					else if (ans[i] == 2) printf("1 2\n");
					else if (ans[i] == 3) printf("1 3\n");
					else if (ans[i] == 4) printf("2 1 2\n");
					else if (ans[i] == 5) printf("2 2 3\n");
					else printf("2 1 3\n");
				exit(0);
			}
			return;
		}
		if (x.sz() && a[dep] == x.c[x.t]) { -- x.t, ans[ ++ cnt] = 1; dfs(dep + 1); -- cnt; }
		if (y.sz() && a[dep] == y.c[y.t]) { -- y.t, ans[ ++ cnt] = 2; dfs(dep + 1); -- cnt; }
		if (z.sz() && a[dep] == z.c[z.t]) { -- z.t, ans[ ++ cnt] = 3; dfs(dep + 1); -- cnt; }
		if (x.c[x.h] == y.c[y.h]) { ++ x.h, ++ y.h, ans[ ++ cnt] = 4; dfs(dep + 1); -- cnt; }
		if (y.c[y.h] == z.c[z.h]) {	++ y.h, ++ z.h, ans[ ++ cnt] = 5; dfs(dep + 1); -- cnt; }
		if (x.c[x.h] == z.c[z.h]) {	++ x.h, ++ z.h, ans[ ++ cnt] = 6; dfs(dep + 1); -- cnt; }
		ans[ ++ cnt] = 1; dfs(dep + 1); -- cnt; ans[ ++ cnt] = 2; dfs(dep + 1); -- cnt; ans[ ++ cnt] = 3; dfs(dep + 1); -- cnt;
	}
	
	int main()
	{
		return dfs(1), 0;
	}
}

int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &k);
	for (reg int i = 1; i <= m; ++ i) scanf("%d", &a[i]);
	if (n == 2 && k == 3) return Subtask2 :: main();
	return Subtask3 :: main();
}
