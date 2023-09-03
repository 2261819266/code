// T2 _ 1s _ 512MB
#include <bits/stdc++.h>
#define FOR(x, l, r) for(int x=l; x<=r; ++x)
#define ROF(x, r, l) for(int x=r; x>=l; --x)
using namespace std;
const int M = 2e6 + 50;
int T, n, m, K, tot, res;
int a[M], num[M], opt[M], pre[M], nxt[M];
int wei[613], lit[M];
priority_queue< pair<int,int> > Dui;

int main()
{
	freopen("meow.in" , "r" , stdin);
	freopen("meow.out", "w" , stdout);
	
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d %d %d", &n, &m, &K);
		res = m;
		FOR (i, 1, m)
		{
			scanf("%d", &a[i]);
			wei[a[i]] = 0;
			pre[i] = i - 1, nxt[i] = i + 1;
			opt[i] = 1, num[i] = 1;
		}
		tot = 1;
		Dui.push(make_pair(0, tot));
		nxt[0] = 1; pre[m + 1] = m;
		
		for (int i=nxt[0]; i<=m; i=nxt[i])
		{
			if (a[pre[i]] == a[i])
			{
				nxt[pre[pre[i]]] = nxt[i];
				pre[nxt[i]] = pre[pre[i]];
				continue;
			}
		}
		for (int i=pre[m+1]; i>=1; i=pre[i])
		{
			if (!wei[a[i]])
			{
				wei[a[i]] = i;
			}
			else
			{
				++ res;
				nxt[pre[wei[a[i]]]] = nxt[wei[a[i]]];
				pre[nxt[wei[a[i]]]] = pre[i];
				
				int one = Dui.top().first;
				int tow = Dui.top().second;
				if (one > wei[a[i]])
				{
					opt[wei[a[i]]] = 2, num[wei[a[i]]] = tow;
					Dui.pop();
					Dui.push(make_pair(wei[a[i]], tow));
				}
				else
				{
					++ tot;
					opt[wei[a[i]]] = 3, num[wei[a[i]]] = tot;
					Dui.push(make_pair(wei[a[i]], tot));
				}
				
				wei[a[i]] = 0;
			}
		}
		
		printf("%d\n", res);
		int cnt = 0;
		FOR (i, 1, m)
		{
			if (opt[i] == 1)
			{
				printf("1 %d\n", num[i]);
			}
			else
			{
				printf("1 %d\n", num[i]);
				lit[++cnt] = num[i];
			}
		}
		FOR (i, 1, cnt)
		{
			printf("2 1 %d\n", lit[i]);
		}
		while (!Dui.empty())
		{
			Dui.pop();
		}
	}
	return 0;
}
