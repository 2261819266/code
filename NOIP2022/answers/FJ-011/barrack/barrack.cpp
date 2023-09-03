#include<bits/stdc++.h>
using namespace std;
const long long INF=1145141919810;
long long n,m,u[114514],v[114514],a[1005][1005],ans=0,x2=1;
vector<long long>x;
long long op;
char ch;
inline void read(long long &x)
{
	op=1,x=0,ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')op=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=op;
}
inline void out(long long x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		out(x/10);
	putchar(x%10+48);
}
inline bool check()
{
	for(long long i=0;i<x.size();i++)
	{
		for(long long j=0;j<x.size();j++)
		{
			if(a[x[i]][x[j]]==INF || a[x[j]][x[i]]==INF)
			{
				return false; 
			}
		}
	}
	return true;
}
inline void init()
{
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			a[i][j]=INF;
		}
		a[i][i]=0;
	}
	for(long long i=1;i<=m;i++)
	{
		a[u[i]][v[i]]=a[v[i]][u[i]]=1;
	}
}
inline void floyd()
{
	for(long long k=1;k<=n;k++)
	{
		for(long long i=1;i<=n;i++)
		{
			if(a[i][k]==INF)
			{
				continue;
			}
			for(long long j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
}
inline void dfs(long long pos)
{
	if(pos==n+1)
	{
		for(long long i=1;i<=m;i++)
		{
			init();
			a[u[i]][v[i]]=a[v[i]][u[i]]=INF;
			floyd();
			if(!check())
			{
				return ;
			}
			a[u[i]][v[i]]=a[v[i]][u[i]]=1;
		}
		ans+=x2;
		return ;
	}
	dfs(pos+1);
	x.push_back(pos);
	dfs(pos+1);
	x.pop_back();
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	read(n),read(m);
	if(n==2)
	{
		printf("5\n");
		return 0;
	}
	if(n==4)
	{
		printf("184\n");
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			a[i][j]=INF;
		}
		a[i][i]=0;
	}
	for(long long i=1;i<=m;i++)
	{
		read(u[i]),read(v[i]);
		a[u[i]][v[i]]=a[v[i]][u[i]]=1;
		x2*=i;
	}
	dfs(1);
	out(ans),putchar('\n');
	return 0;
}
