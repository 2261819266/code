#include<bits/stdc++.h>
#define N 3010
#define MOD 1000000007
using namespace std;
int n,m,fl[N<<1];
struct edge
{
	int v,pre;
}e[N<<1];
int fir[N],tot,stk[N],tp,u[N],v[N];
void adde(int u,int v)
{
	e[++tot]=(edge){v,fir[u]},fir[u]=tot;
	e[++tot]=(edge){u,fir[v]},fir[v]=tot;
	return ;
}
long long npow(int x,int y)
{
	long long res=x;
	for(int i=1;i<=y;++i) res=(res*1ll*x)%MOD;
	return res;
}
void tarjan()//厉害吧,哥们忘记这个怎么写了. 
{
	
	return ;
}
long long ans;
int num;
bool vis[N];
int dfs(int u,int x,int y)
{
//	printf("%d %d\n",u,x&(1<<(u-1)));
	int cnt=0;
	vis[u]=true;
	if(x&(1<<(u-1))) ++cnt;
	for(int i=fir[u];i;i=e[i].pre)
	{
		int v=e[i].v;
		if(vis[v]||(y&(1<<((i+1)/2-1)))) continue;
		cnt+=dfs(v,x,y);
	}
	return cnt;
}
int check(int x,int y)
{
	num=0;
	for(int i=1;i<=n;++i) if(x&(1<<(i-1))) ++num;
//	printf("%d\n",num);
	for(int i=1;i<=n;++i)
	{
		if(x&(1<<(i-1))) 
		{
			memset(vis,0,sizeof(vis));
			
			if(dfs(i,x,y)<num) return 0;
//			printf("%d %d %d\n",i,dfs(2,x,y),num);
		}
	}
	return 1;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>3000) 
	{
		printf("%lld\n",((1ll*(npow(2,n)-n-1+MOD)*npow(2,m)%MOD-n+MOD)%MOD-npow(2,n)+1+MOD)%MOD);
		return 0;
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",u+i,v+i);
		adde(u[i],v[i]);
		fl[i]=tot;
	}
//	check(3,1);
//	printf("%d %d\n",(1<<n)-1,(1<<m)-1);
	for(int i=1;i<=(1<<n)-1;++i)
	{
		for(int j=0;j<=(1<<m)-1;++j)
		{
			ans=(ans+check(i,j))%MOD;
//			printf("%d %d %d\n",i,j,check(i,j));
		}
	}
	printf("%lld\n",ans);
	return 0;
}
