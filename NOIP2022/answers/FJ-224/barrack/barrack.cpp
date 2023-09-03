#include<iostream>
#include<cstring>
#include<cstdio>
int n,m;
int las[500050]={},nex[2000020]={},to[2000020]={};
int V[100]={},E[100]={},S,c,vis[100]={};
int EE[100]={};
long long int ans=0;
void check(int k)
{
	c++;
	vis[k]=1;
	int e=las[k],v=to[e];
	while(v)
	{
		if(EE[e]&&V[v]&&!vis[v])
		{
			check(v);
		}
		e=nex[e];
		v=to[e];
	}
}
void EDfs(int k,int v)
{
	int e=1;
	if(k>m)
	{
		for(int i=1;i<=m;i++)
		{
			EE[i]=EE[i+m]=1;
		}
		for(int i=1;i<=m;i++)
		{
			if(!E[i])
			{
				EE[i]=EE[i+m]=0;
			}
			c=0;
			memset(vis,0,sizeof(vis));
			check(S);
			if(c!=v)
			{
				e=0;
				break;
			}
			EE[i]=EE[i+m]=1;
		}
		ans+=e;
		return;
	}
	E[k]=E[k+m]=0;
	EDfs(k+1,v);
	E[k]=E[k+m]=1;
	EDfs(k+1,v);
}
void VDfs(int k,int v)
{
	if(k>n)
	{
		if(S)EDfs(1,v);
		return;
	}
	V[k]=0;
	VDfs(k+1,v);
	S=k;
	V[k]=1;
	VDfs(k+1,v+1);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		nex[i]=las[x];
		las[x]=i;
		to[i]=y;
		nex[i+m]=las[y];
		las[y]=i+m;
		to[i+m]=x;
	}
	if(n<=8)
	{
		VDfs(1,0);
		printf("%lld",ans);
		return 0;
	}
	
}
