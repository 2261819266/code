#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const long long mod=1000000007;
int h[N*2],nex[N*4],to[N*4],cnt,dl[N];
int n,m,a,b,t,siz[N],e1[N*2],e2[N*2],fa[N];
long long ansn;
stack<int> S;
void add(int f,int t)
{
	++cnt;
	nex[cnt]=h[f];
	to[cnt]=t;
	h[f]=cnt;
}
int sc(int xx)
{
	if(fa[xx]==xx)
		return xx;
	fa[xx]=sc(fa[xx]);
	return fa[xx];
}
void merge(int s1,int s2)
{
	int l1=sc(s1);
	int l2=sc(s2);
	if(l1!=l2)
	{
		fa[l1]=l2;
		siz[l2]+=siz[l1];
	}
}
void dfs(int h)
{
	if(h==m+1)
	{
		for(int i=1;i<=n;i++)
			fa[i]=i,siz[i]=1;
		for(int i=1;i<=m;i++)
			if(dl[i])
				merge(e1[i],e2[i]);
		for(int i=1;i<=n;i++)
			if(fa[i]==i)
				ansn+=(1<<siz[i])-1;
		return ;
	}
	dl[h]=0;
	dfs(h+1);
	dl[h]=1;
	dfs(h+1);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		e1[i]=a;
		e2[i]=b;
		add(a,b);
		add(b,a);
	}
	if(n<=200)
	{
		dfs(1);
		printf("%lld\n",ansn);
	}
	return 0;
}
