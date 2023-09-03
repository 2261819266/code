#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis1[10],vis2[11];
long long ans=0;
struct node
{
	int x;
	int y;
}oe[20];
struct EDGE
{
	int v;
	int w;
	int next;
}edge[100];
int head[100],num=0;
void add(int u,int v,int w)
{
	edge[++num].v=v;
	edge[num].w=w;
	edge[num].next=head[u];
	head[u]=num;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int viss[100],dis[100];
int check()
{
	memset(edge,0,sizeof(edge));
	memset(head,0,sizeof(head));
	memset(dis,0x3f,sizeof(dis));
	memset(viss,0,sizeof(viss));
	num=0;
	while(!q.empty())q.pop();
	for (int i=1;i<=m;i++)
	{
		if(vis2[i])
		{
			add(oe[i].x,oe[i].y,1);
			add(oe[i].y,oe[i].x,1);
		}
	}
	
	int sum=0; 
	for (int i=1;i<=n;i++)
	{
		if(vis1[i])
		{
			if(sum==0)
			{
				q.push(make_pair(0,i));
				dis[i]=0;
			}
			sum++;
		} 
	}
	if(sum==0)return 0;
	if(sum==1)return 1;
	
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		
		if(viss[now])continue;
		else viss[now]=1;
		
		for (int i=head[now];i;i=edge[i].next)
		{
			int v=edge[i].v;
			int w=edge[i].w;
			if(dis[v]>=dis[now]+w)
			{
				dis[v]=dis[now]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	
	for (int i=1;i<=n;i++)
	{
		if(vis1[i])
		{
			if(dis[i]==0x3f3f3f3f)
			{
				return 0;
			}
		} 
	}
	return 1;
}

void dfs2(int now,int vis[11])
{
	if(now==m+1)
	{
		for (int i=1;i<=m;i++)
		{
			vis2[i]=vis[i];
		}
		
		int x=check();
		ans+=x;
//		if(x)
//		{
//			cout<<"Point:";
//			for (int i=1;i<=n;i++)
//			if(vis1[i])cout<<i<<" ";
//			cout<<"Edge:";
//			for (int i=1;i<=m;i++)
//			if(vis2[i])cout<<i<<" ";
//			cout<<endl;
//		}
	}
	else
	{
		vis[now]=0;
		dfs2(now+1,vis);
		vis[now]=1;
		dfs2(now+1,vis);
	}
}
void dfs1(int now,int vis[10])
{
	if(now==n+1)
	{
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			vis1[i]=vis[i];
			if(vis[i])sum++;
		}
		if(sum==0)return ;
		int xxx[11]={ };
		dfs2(1,xxx);
	}
	else
	{
		vis[now]=0;
		dfs1(now+1,vis);
		vis[now]=1;
		dfs1(now+1,vis);
	}
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	int xxx[10]={ };
	
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&oe[i].x,&oe[i].y);
	}
	dfs1(1,xxx);
	cout<<ans<<endl;
	return 0;
}
/*
	我果然还是太菜了,最后还是只能打暴力 
*/
