#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
const LL N = 5e5 + 10, M = 1e6 + 10, mod = 1e9 + 7, INF = 1e18;

LL n, m;
vector<LL> g[N];
PLL edge[M];
bool st[N];
LL d[N];
LL dist[N];
LL res;

LL qmi(LL a, LL b)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

bool check(LL x, LL s)
{
	for (LL i = 1; i <= n; i ++ ) dist[i] = INF;
	queue<LL> q;
	q.push(s);
	dist[s] = 0;
	while (q.size())
	{
		LL t = q.front();
		q.pop();
		for (LL i = 0; i < (LL)g[t].size(); i ++ )
		{
			LL j = g[t][i];
			if (t == edge[x].first && j == edge[x].second) continue;
			if (dist[j] == INF)
			{
				q.push(j);
				dist[j] = dist[t] + 1;
			}
		}
	}
	for (LL i = 1; i <= n; i ++ )
		if (st[i] && dist[i] == INF)
			return false;
	return true;
}

void dfs(LL x)
{
	if (x > n)
	{
		LL cnt = 0, start = -INF;
		for (LL i = 1; i <= n; i ++ )
			if (st[i])
			{
				start = i;
				break;
			}
		if (start == -INF) return;
		for (LL i = 1; i <= m; i ++ )
			if (check(i, start))
				cnt ++ ;
		res = (res + qmi(2, cnt)) % mod;
		return;
	}
	st[x] = true;
	dfs(x + 1);
	st[x] = false;
	dfs(x + 1);
}

int main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (LL i = 0; i < m; i ++ )
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
		edge[i + 1] = {a, b};
	}
	dfs(1);
	printf("%lld\n", res);
	return 0;
}
