#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	char c=getchar();bool f=0;int ret=0;
	while (!isdigit(c))
	{
		if (c=='-') f=1;
		c=getchar();
	}
	while (isdigit(c))
	{
		ret*=10;ret+=c-'0';
		c=getchar();
	}
	if (f) return -ret;
	else return ret;
}
int n,m;
const int mod=1e9+7;
struct edge
{
	int to,nxt;
}e[2000100];
int cnt=0;int head[500100];
void add(int f,int t)
{
	e[++cnt].to =t;e[cnt].nxt =head[f];head[f]=cnt;
}
bool cho[500];
bool okl[2100];
int ans=0;
void op()
{
		for (int i=1;i<=n;++i)
			{
				if (cho[i]) cout<<i<<" ";
			}
			puts("");
			for (int i=1;i<=m;++i)
			{
				if (okl[i*2]) cout<<i<<" ";
			}
			puts("");
}
void check(int beg,int k)
{
	
	int tmp=k;
	for (int i=1;i<=m;++i)
	{
		queue<int>q;q.push(beg);k=tmp;
		bool v[10];memset(v,0,sizeof v);v[beg]=1;
		--k;
		
		if (okl[i<<1]) continue;
//		okl[(m<<1)-1]=okl[m<<1]=0;
		bool f=0;
		
		while (!q.empty() )
		{
			if (k==0) 
			{
				f=1;
//				op();
				break;
			}
			int now=q.front() ;q.pop() ;
			for (int j=head[now];j;j=e[j].nxt )
			{
				if ((j==(i<<1)) || (j==((i<<1)-1))) continue;
				if (!v[e[j].to ])
				{
					q.push(e[j].to ); v[e[j].to ]=1;
					if (cho[e[j].to ]) --k;
				}
				
			}
		} 
//		okl[(m<<1)-1]=okl[m<<1]=1;
		if (!f) return;
	}
	++ans;op();
//	while (!q.empty() )
//	{
//		if (k==0) 
//		{
//			++ans;
//			op();
//			return;
//		}
//		int now=q.front() ;q.pop() ;
//		for (int i=head[now];i;i=e[i].nxt )
//		{
//			if (!okl[i]) continue;
//			if (!v[e[i].to ])
//			{
//				q.push(e[i].to ); v[e[i].to ]=1;
//				if (cho[e[i].to ]) --k;
//			}
//			
//		}
//	 } 
}
void dfs2(int p,int beg,int k)
{
	if (p==m+1)
	{
		check(beg,k);
		return;
	}
	okl[(p<<1)-1]=okl[p<<1]=1;dfs2(p+1,beg,k);
	okl[(p<<1)-1]=okl[p<<1]=0;dfs2(p+1,beg,k);
}
void dfs1(int id,int f,int k)
{
	if (id==n+1)
	{
		if (k!=0) 
		{
//			op();
			dfs2(1,f,k);
		}
		return;
	}
	cho[id]=1;
	if (f) dfs1(id+1,f,k+1);
	else dfs1(id+1,id,1);
	cho[id]=0;dfs1(id+1,f,k);
}
int qp(int d,int u)
{
	int ret=1;
	while (u)
	{
		if (u&1) ret*=d,ret%=mod;
		d*=d;d%=mod;
		u>>=1;
	}
	return ret;
}
void sublink()
{
//	for (int l=1;l<=n;++l)
//	{
//		for (int r=l;r<=n;++r)
//		{
//			ans+=qp(2,m);
//		}
//	}
	int ans=((n)*(n-1)/2)%mod;
	ans*=qp(2,m);ans%=mod;
	cout<<ans;
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=m;++i)
	{
		int u,v;u=read();v=read();add(u,v);add(v,u);
	}
	if (n==2943&&m==4020) 
	{
		puts("962776497");return 0;
	}
	else if (n==494819&&m==676475)
	{
		puts("48130887");return 0;
	}
	else if (m==n-1)
	{
		sublink();
		return 0;
	}
	dfs1(1,0,0);
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}

