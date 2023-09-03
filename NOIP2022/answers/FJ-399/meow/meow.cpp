#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

//typedef pair<int, int> PII;

const int N = 605, M = 2e6 + 10;

struct PUTOUT
{
	int op, l, r;
}res[M << 2];

int T, n, m, k;
int a[M], ups[N], dws[N], sz[N];
int vis[N], pos[M];
set<int> st;
int tot;

int main()
{
//	freopen("meow.in", "r", stdin);
//	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	while(T -- )
	{
		tot = 0;
		scanf("%d%d%d", &n, &m, &k); st.clear();
		for(int i = 1; i <= m; i ++ )
			scanf("%d", &a[i]), pos[a[i]] = vis[a[i]] = 0;
		for(int i = 1; i <= n; i ++ ) st.insert(i);
		if(k == 2 * n - 2)
		{
			//cout << 1 << endl;
			for(int i = 1; i <= m; i ++ )
			{
				if(vis[a[i]])
				{
					if(pos[a[i]] == 1)
					{
//						printf("1 %d\n", vis[a[i]]);
						res[++tot].op = 1; res[tot].l = vis[a[i]]; res[tot].r = 0;
						//if(ups[vis[a[i]]] == dws[vis[a[i]]]) ups[vis[a[i]]] = dws[vis[a[i]]] = 0;
						//else ups[vis[a[i]]] = dws[vis[a[i]]];
					}
					if(pos[a[i]] == 0)
					{
//						printf("1 %d\n", n);
						res[++tot].op = 1; res[tot].l = n; res[tot].r = 0;
//						printf("2 %d %d\n", vis[a[i]], n);
						res[++tot].op = 2; res[tot].l = vis[a[i]]; res[tot].r = n;
						//if(ups[vis[a[i]]] == dws[vis[a[i]]]) ups[vis[a[i]]] = dws[vis[a[i]]] = 0;
						//else dws[vis[a[i]]] = ups[vis[a[i]]];
					}
					sz[vis[a[i]]] -- ; st.insert(vis[a[i]]);
					vis[a[i]] = 0; pos[a[i]] = 0;
				}
				else
				{
					int id = *st.begin(); vis[a[i]] = id;
//					printf("1 %d\n", id);
					res[++tot].op = 1; res[tot].l = id; res[tot].r = 0;
					if(!sz[id]) pos[a[i]] = 0;
					else pos[a[i]] = 1;
					sz[id] ++ ;
					if(sz[id] == 2) st.erase(st.begin());
				}
			}
			printf("%d\n", tot);
			for(int i = 1; i <= tot; i ++ )
			{
				if(res[i].r == 0) printf("%d %d\n", res[i].op, res[i].l);
				else printf("%d %d %d\n", res[i].op, res[i].l, res[i].r);
			}
		}
		else
		{
			/*for(int i = 1; i <= m; i ++ )
			{
				if(vis[a[i]])
				{
					if(pos[a[i]] == 1)
					{
						res[++tot].op = 1; res[tot].l = vis[a[i]]; res[tot].r = 0;
					}
					if(pos[a[i]] == 0)
					{
						res[++tot].op = 1; res[tot].l = n; res[tot].r = 0;
						res[++tot].op = 2; res[tot].l = vis[a[i]]; res[tot].r = n;
					}
					sz[vis[a[i]]] -- ; st.insert(vis[a[i]]);
					vis[a[i]] = 0; pos[a[i]] = 0;
				}
				else
				{
					if(st.size() == 1)
					{
						
					}
					int id = *st.begin(); vis[a[i]] = id;
//					printf("1 %d\n", id);
					res[++tot].op = 1; res[tot].l = id; res[tot].r = 0;
					if(!sz[id]) pos[a[i]] = 0;
					else pos[a[i]] = 1;
					sz[id] ++ ;
					if(sz[id] == 2) st.erase(st.begin());
				}
			}
			printf("%d\n", tot);
			for(int i = 1; i <= tot; i ++ )
			{
				if(res[i].r == 0) printf("%d %d\n", res[i].op, res[i].l);
				else printf("%d %d %d\n", res[i].op, res[i].l, res[i].r);
			}*/
			
		}
	}
	return 0;
}
