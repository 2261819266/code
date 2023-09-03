#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int res=0,flag=1;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9'))
		flag=(ch=='-')?-1:1,ch=getchar();
	while('0'<=ch&&ch<='9')
		res=res*10+ch-'0',ch=getchar();
	return res*flag;
}
const int mod=1e9+7;
struct graph
{
	struct edge
	{
		int fr,to,nxt;
	};
	int n,tot;
	int head[500010];
	struct edge ed[1000010];
	void add_edge(int fr,int to)
	{
		ed[++tot]=(edge){fr,to,head[fr]};
		head[fr]=tot;
	}
};
struct graph a,b;
int m;
int size[500010];
namespace Tarjan
{
	stack<int> s;
	set<pair<int,int> > mp;
	int cnt=0;
	bool instack[500010];
	int dfn[500010],low[500010],col[500010];
	void tarjan(int fa,int fr)
	{
		s.push(fr);
		instack[fr]=true;
		dfn[fr]=low[fr]=++cnt;
		for(int i=a.head[fr];i!=0;i=a.ed[i].nxt)
		{
			int to=a.ed[i].to;
			if(fa==to)
				continue;
			if(dfn[to]==0)
			{
				tarjan(fr,to);
				low[fr]=min(low[fr],low[to]);
			}
			else if(instack[to]==true)
				low[fr]=min(low[fr],dfn[to]);
		}
		if(dfn[fr]==low[fr])
		{
			b.n++;
			int tmp=0;
			while(s.empty()==false)
			{
				int to=s.top();
				instack[to]=false;
				col[to]=b.n;
				s.pop();
				tmp++;
				if(fr==to)
					break;
			}
			size[b.n]=tmp;
		}
	}
	void rebuild()
	{
		for(int i=1;i<=a.n;i++)
			if(dfn[i]==0)
				tarjan(0,i);
		for(int i=1;i<=a.tot;i++)
		{
			int fr=col[a.ed[i].fr];
			int to=col[a.ed[i].to];
			if(fr!=to&&mp.find(make_pair(fr,to))==mp.end())
			{
				b.add_edge(fr,to);
				b.add_edge(to,fr);
				//cout<<"Add_edge:"<<a.ed[i].fr<<" "<<a.ed[i].to<<" "<<fr<<" "<<to<<endl;
				mp.insert(make_pair(fr,to));
				mp.insert(make_pair(to,fr));
			}
		}
	}
};
namespace Math
{
	inline long long quick(long long a,long long b)
	{
		long long res=1;
		while(b!=0)
		{
			if(b&1)
				res=res*a%mod;
			a=a*a%mod;
			b>>=1;
		}
		return res%mod;
	}
	int run(int n,int m)
	{
		long long res=1;
		for(int i=2;i<=m;i++)
			res=(long long)res*i%mod;
		for(int i=1;i<=(m-n);i++)
			res=(long long)res*quick(i,mod-2)%mod;
		for(int i=1;i<=n;i++)
			res=(long long)res*quick(i,mod-2)%mod;
		return res%mod;
	}
};
int ans[500010];
//0: pos 0 road 0;
//1: pos 1 road 0;
//2: pos 0 road 1;
//3: pos 1 road 1;
//void dfs(int fa,int fr)
//{
//	cout<<fa<<" "<<fr<<" "<<size[fr]<<endl;
//	dp[fr][0]=0;
//	for(int i=1;i<=size[fr];i++)
//		dp[fr][1]=(dp[fr][1]+Math::run(i,size[fr]))%mod;
//	dp[fr][1]=dp[fr][1]*(dp[fr][1]+1)%mod;
//	dp[fr][2]=1;
//	dp[fr][3]=dp[fr][1];
//	for(int i=b.head[fr];i!=0;i=b.ed[i].nxt)
//	{
//		int to=b.ed[i].to;
//		if(to==fa)
//			continue;
//		dfs(fr,to);
//		dp[fr][0]=(dp[fr][0]+dp[to][0]+dp[to][1]+dp[to][2]+dp[to][3])%mod;
//		dp[fr][1]=(dp[fr][1]+dp[to][0])%mod;
//		dp[fr][3]=(dp[fr][3]*((dp[to][2]+dp[to][3])%mod))%mod;
//	}
//	printf("fr:%d %d %d %d\n",dp[fr][0],dp[fr][1],dp[fr][2],dp[fr][3]);
//}
int dp[500010][3];
void dfs(int fa,int fr)
{
	dp[fr][0]=1;
	dp[fr][1]=ans[fr];
	dp[fr][2]=ans[fr]+1;
	//printf("fr:%d %d %d %d\n",fr,dp[fr][0],dp[fr][1],dp[fr][2]);
	for(int i=b.head[fr];i!=0;i=b.ed[i].nxt)
	{
		int to=b.ed[i].to;
		if(to==fa)
			continue;
		dfs(fr,to);
		dp[fr][0]=(dp[fr][0]+dp[to][0]+dp[to][1]+dp[to][2])%mod;
		dp[fr][1]=(dp[fr][1]+dp[to][0]+dp[to][2])%mod;
		dp[fr][2]=(dp[fr][2]+dp[to][0]+dp[to][2])%mod;
	}
	printf("fr:%d %d %d %d\n",fr,dp[fr][0],dp[fr][1],dp[fr][2]);
}
namespace getans
{
	int tmp[500010];
	int sum[500010];
	void init()
	{
		for(int i=1;i<=m-1;i++)
			tmp[i]=Math::run(i,m-1)%mod;
		for(int i=1;i<=m;i++)
			sum[i]=(sum[i-1]+tmp[i])%mod;
	}
	void getans()
	{
		init();
		for(int i=1;i<=b.n;i++)
		{
			//if(size[i]==1)
			//	size[i]++;
			ans[0]=(ans[0]+size[i]*sum[m-size[i]])%mod;
			//cout<<"getans:"<<ans[0]<<" "<<m-size[i]<<" "<<sum[m-size[i]]<<endl;
		}
	}
};
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	a.n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int fr=read(),to=read();
		a.add_edge(fr,to);
		a.add_edge(to,fr);
	}
	Tarjan::rebuild();
	for(int i=1;i<=b.n;i++)
	{
		for(int j=1;j<=size[i];j++)
			ans[i]=(ans[i]+Math::run(j,size[i]))%mod;
		if(size[i]!=1)
			ans[i]=ans[i]*(ans[i]+1)%mod;
	}
	dfs(0,1);
	//getans::getans();
	printf("%d",(dp[1][1]+ans[0])%mod);
	return 0;
}
