#include<bits/stdc++.h>
using namespace std;
int n,m,x[30],y[30],head[600001],to[1100001],nex[1100001],cnt;
long long ans,mod=1e9+7,Pow[600001];
bool b[30],bb[30],bbb[30];
inline void add(int x,int y)
{
	to[++cnt]=y;
	nex[cnt]=head[x];
	head[x]=cnt;
}
inline int read()
{
	int x=0;
	char c;
	while(c=getchar())if(c>='0'&&c<='9')break;
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
inline bool check()
{
	int sum=0;
	for(int i=1;i<=n;++i)if(bb[i])++sum;
	if(!sum)return false;
	int jjx;
	for(int i=1;i<=n;++i)
	{
		if(bb[i])
		{
			jjx=i;
			break;
		}
	}
	for(int j=1;j<=m;++j)
	{
		if(b[j])continue;
		queue<int>q;
		memset(bbb,false,sizeof(bbb));
		bbb[jjx]=1;
		int now=1;
		q.push(jjx);
		while(!q.empty())
		{
			int X=q.front();
			q.pop();
			for(int i=head[X];i;i=nex[i])
			{
				if((i+1)/2==j)continue;
				int Y=to[i];
				if(!bbb[Y]&&(bb[Y]))
				{
					bbb[Y]=1;
					q.push(Y);
					++now;
				}
			}
		}
		if(now<sum)return false;
	}
	return true;
}
inline void dfs(int o)
{
	if(o==m+n+1)
	{
		if(check())++ans;
		return;
	}
	if(o<=m)
	{
		b[o]=1;
		dfs(o+1);
		b[o]=0;
		dfs(o+1);
	}
	else
	{
		bb[o-m]=1;
		dfs(o+1);
		bb[o-m]=0;
		dfs(o+1);
	}
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	m=read();
	if(m<=25)
	{
		for(int i=1;i<=m;++i)
		{
			x[i]=read();
			y[i]=read();
			add(x[i],y[i]);
			add(y[i],x[i]);
		}
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	ans=1;
	Pow[0]=1;
	for(int i=2;i<=n;++i)Pow[i]=(Pow[i-1]*2LL)%mod;
	for(int i=2;i<=n;++i)
	{
		long long ANS=ans;
		ans=(ans+ANS)%mod;
		ans=(ans+ANS)%mod;
		ans=(ans+Pow[n-1])%mod;
	}
	printf("%lld",ans);
}