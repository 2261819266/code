
//我，CCF，打钱，给分 

#include<iostream>
#include<cstdio>
#define re register
#define ll long long
#define rll re ll
inline void write(rll x)
{
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
inline ll read()
{
	rll x=0,c=0;re char a=getchar();
	for(;a<'0'||a>'9';a=getchar())c|=a==45;
	for(;a>='0'&&a<='9';a=getchar())x=(x<<3)+(x<<1)+(a^48);
	return c?-x:x;
}
#define R read()
using namespace std;

struct Edge
{
	ll next,to;
}e[2919810];
ll head[114514],vis[114514],cnt=0,ans,n,m;
inline void add()
{
	rll u=R,v=R;
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;

	e[++cnt].to=u;
	e[cnt].next=head[v];
	head[v]=cnt;
}
inline void dfs(rll x)
{
	++ans;
	vis[x]=1;
	for(rll i=head[x];i;i=e[i].next)
	{
		++ans;
		if(!vis[e[i].to])
			dfs(e[i].to);
	}
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);

	n=R,m=R;
	for(rll i=1;i<=m;++i)add();
	for(rll i=1;i<=n;++i)
	{
		for(rll j=i;j<=n;++j)vis[j]=0;
		dfs(i);
	}
	write(ans);
	return 0;
}
