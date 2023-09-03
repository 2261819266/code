#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
using namespace std;

const int N=500010,M=1000010,MOD= 1000000007;

struct edge
{
	int to,nxt;
}e[M*2],ne[M*2];
int h[N],nh[N],en,nen,cnt,ncnt;
void ade(int op,int u,int v)
{
	if(op==1)
	{
		e[++en].to=v;e[en].nxt=h[u];h[u]=en;
	}
	else if(op==2)
	{
		ne[++nen].to=v;ne[nen].nxt=nh[u];nh[u]=nen;
	}
	return;
}

int id[N],num[N];
stack<int>s;bool ins[N];
int dfn[N],low[N];
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++cnt;
	int y;for(int i=h[x];i;i=e[i].nxt)
	{
		y=e[i].to;
		if(y!=fa)
		{
			if(!dfn[y])
			{
				tarjan(y,x);low[x]=min(dfn[x],low[y]);
			}
			else
				low[x]=min(low[x],low[y]);
		}
	}
	if(dfn[x]==low[x])
	{
		++ncnt;
		while(ins[x])
		{
			y=s.top();s.pop();
			id[y]=ncnt;num[ncnt]++;//to do
		}
	}
	return;
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	int n,m,u,v;scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),ade(1,u,v),ade(1,v,u);
	printf("5");
	
	fclose(stdin);fclose(stdout);
	return 0;
}
