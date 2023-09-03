#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e6+10,mod=1e9+7; 
inline int read()
{
	int n=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=(n<<3)+(n<<1)+(ch-'0');
		ch=getchar();
	}
	return n*f;
}
ll ans;
int n,m;
int head[M],to[M],tot,nxt[M];
ll f[M];
bool vis[M],can[M];
void add(int u,int v)
{
	nxt[++tot]=head[u];
	head[u]=tot;
	to[tot]=v;
}
int cnt=0;
int dian;
void dfs(int x)
{
	dian+=1<<(x-1); 
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(!can[i])
		  continue;
		if(vis[y])
		  continue;
		dfs(y);
	}
}
void work1(int x)
{
	if(x>m)
	{
		cnt++;
		for(int i=1;i<=n;i++)
		   vis[i]=0;
//		for(int i=1;i<=m;i++)    cout<<can[i*2-1]<<" ";cout<<endl;
		    
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			  continue;
			dian=0;
			dfs(i);
			for(int s=dian;s!=0;s=(s-1)&dian)
			   if(s-(s&-s)!=0)
			   f[s]++;
		}
		return ;
	}
	can[x*2]=0;
	can[x*2-1]=0;
	
	work1(x+1); 
	
	can[x*2]=1;
	can[x*2-1]=1;
	work1(x+1); 
} 
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	work1(1);
	for(int i=1;i<(1<<n);i++)
	   ans=(ans+f[i])%mod;
	   
	ans=(ans+cnt*n%mod)%mod;
	
	printf("%lld",ans);
}
/*
4 4
1 2
2 3
3 1
1 4
*/
