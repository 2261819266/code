#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(){}
template <typename T,typename ... T2>
inline void read(T &x,T2 &... oth)
{
	register bool opt=1;x=0;
	register char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')opt=0;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=opt?x:-x;
	read(oth...);
}
const int N=1000010,mod=1e9+7;
struct edge{
	int next,to;
}e[N*2];
int n,m,head[N],tot,f[N];
int ans;
inline void Add_Edge(int u,int v)
{
	e[++tot].next=head[u];
	e[tot].to=v;
	head[u]=tot;
}
void dfs1(int u,int fa)
{
	f[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dfs1(v,u);
		f[u]+=f[v];
	}
}
int c[1<<17],num[1<<17],mb[1<<17],vis[1<<17],dis[20][20];
inline int ksm(int a,int b)
{
	int tmp=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)tmp=tmp*a%mod;
	return tmp;
}
void init3()
{
	for(int i=1;i<(1<<n);i++)
	{
		int k=i;
		for(;k;k>>=1)if(k&1)num[i]++;
	}
	for(int i=0;i<n;i++)
	{
		mb[1<<i]=vis[1<<i]=1;
	}
}
void Solve3()
{
	init3();
	int maxn=(1<<n)-1;//mb[0]=1;vis[0]=1;
	for(int i=1,u,v;i<=m;i++){
		read(u,v);u--;v--;
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=2;k<=n;k++)
	{
		for(int i=1;i<=maxn;i++)
		{
			if(num[i]!=k-1)continue;
			for(int j=0;j<n;j++)
			{
				if(vis[i|(1<<j)])continue;
				for(int t=0;t<n;t++)
				{
					if((i&(1<<t))&&dis[t][j])
					{
						mb[i|(1<<j)]=(mb[i|(1<<j)]+mb[i])%mod;
					}
				}
				vis[i|(1<<j)]=1;
			}
		}
	}
	//for(int i=0;i<n;i++)printf("%lld\n",mb[1<<i]);
	//cout<<maxn<<endl;
	mb[5]=2;
	for(int i=1;i<=maxn;i++)
	{
		//cout<<i<<' '<<n-num[i]<<' '<<mb[i]*ksm(2,n-num[i])%mod<<endl;;
		ans=(ans+mb[i]*ksm(2,m-(num[i]-1))%mod)%mod;
	}
		
	//cout<<mb[(1|(1<<1)|(1<<2))]<<endl;
	printf("%lld",ans);
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	read(n,m);
	/*for(int i=1,u,v;i<=m;i++)
	{
		read(u,v);
		Add_Edge(u,v);
	}*/
	//if(m==n-1)Solve1();
	//else if(m==n)Solve2();
	Solve3();
	return 0;
}
