#include<bits/stdc++.h>
#define ll long long
const int N = 2e6 + 5;
using namespace std;
int T, n, m, k;
int a[N], tot, ans[2 * N][3];
list < int > q[25];
bool dfs(int x)
{
	if(x == m + 1)
	{
		bool flag = true;
		for(int i = 1; i <= k; i++)
		{
			if(!q[i].empty())
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	for(int i = 1; i <= k; i++)
	{
		if(!q[i].empty() && q[i].back() == a[x])
		{
			q[i].pop_back();
			tot++;
			ans[tot][0] = 1;
			ans[tot][1] = i;
			if(dfs(x + 1) == true)
			{
				return true;
			}
			tot--;
			q[i].push_back(a[x]);
		}
		else
		{
			q[i].push_back(a[x]);
			tot++;
			ans[tot][0] = 1;
			ans[tot][1] = i;
			if(dfs(x + 1) == true)
			{
				return true;
			}
			tot--;
			q[i].pop_back();
		}
	}
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(i == j) continue;
			if(!q[i].empty() && !q[j].empty())
			if(q[i].front() == q[j].front())
			{
				int p = q[j].front();
				tot++;
				ans[tot][0] = 2;
				ans[tot][1] = i;
				ans[tot][2] = j;
				q[i].pop_front();
				q[j].pop_front();
				if(dfs(x) == true)
				{
					return true;
				}
				tot--;
				q[i].push_front(p);
				q[i].push_front(p);
			}
		}
	}
	return false;
}
int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	for(int z = 1; z <= T; z++)
	{
		scanf("%d%d%d", &k, &m, &n);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d", &a[i]);
		}
		tot = 0;
		dfs(1);
		printf("%d\n", tot);
		for(int i = 1; i <= tot; i++)
		{
			printf("%d %d", ans[i][0], ans[i][1]);
			if(ans[i][0] == 2)
			{
				printf(" %d", ans[i][2]);
			}
			printf("\n");
		}
	}
	return 0;
}