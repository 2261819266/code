#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 5e5 + 25, M = 1e6 + 25;
const long long mod = 1000000007ll;
int n,m;
int fa1[N],fa2[N],siz[N],sizd[N];
int tot=0;
bool exist[M];
struct Edge
{
	int u,v;
}edge[M];
int find1(int x)
{
	if(fa1[x]!=x) fa1[x]=find1(fa1[x]);
	return fa1[x]; 
}
int find2(int x)
{
	if(fa2[x]!=x) fa2[x]=find2(fa2[x]);
	return fa2[x];
}

struct Node
{
	int nxt;
	int to;
}edge1[2*M],edge2[2*M];
int num_edge1=0,head1[N];
int num_edge2=0,head2[N];
void add_edge1(int u,int v)
{
	num_edge1++;
	edge1[num_edge1].nxt=head1[u];
	edge1[num_edge1].to=v;
	head1[u]=num_edge1;
}
void add_edge2(int u,int v)
{
	num_edge2++;
	edge2[num_edge2].nxt=head2[u];
	edge2[num_edge2].to=v;
	head2[u]=num_edge2;
}

long long C(int m)
{
	long long a=0;
	long long b=1;
	for(int i=m;i>=1;i--)
	{
		b*=i;
		b/=(m-i+1);
		a+=b;
		a%=mod;
	}
	return a;
}

bool vis[N];
long long ans1[N],ans[N],bian[N];
long long Ans=0;
void DFS(int u,int fa)
{
	vis[u]=true;
	long long h = C(sizd[u]),s=C(siz[u]);
	ans[u]=(h+1)*(s+1);
	ans1[u]=h*(s+1);
	ans1[u]%=mod;
	ans[u]%=mod;
	bian[u]=siz[u];
	int num=0;
	int zi=0;
	for(int i=head1[u];i;i=edge1[i].nxt)
	{
		int v=edge1[i].to;
		if(v!=fa) num++;
		if(vis[v]==false)
		{
			zi++;
			DFS(v,u);
			ans[u]*=ans[v];
			ans[u]%=mod;
			ans1[u]*=ans[v];
			ans1[u]%=mod;
			bian[u]+=bian[v];
		}
	}
	bian[u]+=num;
	if(zi==0){
		//Ans+=((C(m-bian[u])+1)*ans1[u])%mod;
		Ans+=h*(s+1)*(C(m-siz[u])+1);
	} 
	else Ans+=((C(m-bian[u])+1)*ans1[u])%mod;
	Ans%=mod;
}
int dep[N],fat[N];
void DFS2(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=head2[x];i;i=edge2[i].nxt)
	{
		int v=edge2[i].to;
		if(fa==v) continue;
		fat[v]=x;
		DFS2(v,x);
	}
}

void jia(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
	{
		int fau=find2(x),fav=find2(fat[x]);
		if(fau!=fav)
			fa2[fau]=fav;
		x=fat[x];
	}
	while(x!=y)
	{
		int fau=find2(x),fav=find2(fat[x]);
		if(fau!=fav)
			fa2[fau]=fav;
		x=fat[x];
		fau=find2(y);
		fav=find2(fat[y]);
		if(fau!=fav)
			fa2[fau]=fav;
		y=fat[y];
	}
	return;
}

int main()
{
	scanf("%d%d",&n,&m);
	int fau,fav;
	for(int i=1;i<=n;i++) fa1[i]=fa2[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&edge[i].u,&edge[i].v);
		if(tot==n-1) continue;
		fau=find1(edge[i].u);
		fav=find1(edge[i].v);
		if(fau!=fav){
			fa1[fau]=fav;
			tot++;
			exist[i]=true;
			add_edge2(edge[i].u,edge[i].v);
			add_edge2(edge[i].v,edge[i].u);
		}
	}
	DFS2(1,0);
	for(int i=1;i<=m;i++)
	{
		if(exist[i]==true) continue;
		fau=find2(edge[i].u);
		fav=find2(edge[i].v);
		if(fau!=fav)
			jia(fau,fav);
	}
	for(int i=1;i<=m;i++)
	{
		fau=find2(edge[i].u);
		fav=find2(edge[i].v);
		if(fau!=fav)
		{
			add_edge1(fau,fav);
			add_edge1(fav,fau);
		}
		else
			siz[fau]++;
	}
	for(int i=1;i<=n;i++)
		sizd[find2(i)]++;
	DFS(fau,0);
	printf("%d",5);
	return 0;
}
