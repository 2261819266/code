#include<iostream>
#include<queue>
#include<cstdio>

const int N = 2e6 + 5;
const int M = 305;
int a[N],n,m,k;
int p[N],vis[M];
int stk[M][2];
int ans[N],ans_len;

struct node{int val,id;};node q[N];

struct Heap_Node
{
	int pos,id;
	bool operator< (const Heap_Node v)const
	{
		return p[id] < p[v.id];
	}
};
std::priority_queue<Heap_Node> H;
int d[N],tot;

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&m,&n,&k);
		for(int i = 1;i <= n;++i)scanf("%d",a+i);
		int len = 0;ans_len = n;
		for(int i = 1;i <= n;++i)
		{
			if(len > 0 && q[len].val == a[i])
			{
				ans[q[len].val] = 1;
				ans[i] = 1;
				--len;
			}
			else
				q[++len] = {a[i],i};
		}
		std::swap(n,len);
		for(int i = 1;i <= n;++i)
		{
			if(vis[q[i].val])
			{
				p[i] = vis[q[i].val];
				p[vis[q[i].val]] = i;
				vis[q[i].val] = 0;
			}
			else
				vis[q[i].val] = i;
		}
		for(int i = 1;i <= m;++i)d[i] = i;tot = m;
		while(!H.empty())H.pop();
		for(int i = 1;i <= n;++i)
		{
			while(!H.empty() && stk[H.top().pos][0] != H.top().id)H.pop();
			if(p[i] > i)
			{
				if(tot > ((k+1)&1) && (H.empty() || p[i] > p[H.top().id]))
				{
					ans[q[i].id] = d[tot];
					stk[d[tot]][0] = i;
					H.push({d[tot],i});
					--tot;
				}
				else
				{
					Heap_Node v = H.top();
					ans[q[i].id] = v.pos;
					stk[v.pos][1] = i;
					H.pop();
				}
			}
			else
			{
				int j = p[i],u = ans[j];
				if(stk[u][0] == j)
				{
					if(!stk[u][1])
					{
						ans[q[i].id] = u;
						stk[u][0] = 0;
						d[++tot] = u;
					}
					else
					{
						ans[q[i].id] = d[tot];
						++ans_len;
						int v = stk[u][1];
						stk[u][1] = 0;
						stk[u][0] = v;
						H.push({u,v});
					}
				}
				else
				{
					ans[q[i].id] = u;
					stk[u][1] = 0;
					H.push({u,stk[u][0]});
				}
			}
		}
		n = len;
		printf("%d\n",ans_len);
		for(int i = 1;i <= n;++i)
		{
			printf("1 %d\n",ans[i]);
			if(p[i] < i && ans[i] != ans[p[i]])
				printf("2 %d %d\n",ans[i],ans[p[i]]);
		}
	}
}
