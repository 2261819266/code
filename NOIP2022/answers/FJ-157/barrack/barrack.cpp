#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=1e6+5;
const int Mod=1e9+7;
struct Edge{
	int u,v;
}eg[N];
struct edge{
	int v,nx;
}e[M<<1];
int n,m,ne=1,ans,cnt,f[N];
bool vis[N];
void read(int u,int v)
{	e[++ne].v=v;
	e[ne].nx=f[u];
	f[u]=ne;
}
int qpow(int x,int k)
{	int res=1;
	while(k)
	{	if(k&1)res=1ll*res*x%Mod;
		x=1ll*x*x%Mod,k>>=1;
	}
	return res;
}
bool p1()
{	for(int i=1;i<=m;i++)
		if(eg[i].u!=i||eg[i].v!=i+1)return 0;
	int res=1ll*n*qpow(2,n-1)%Mod;
	for(int i=2;i<=n;i++)res=(res+1ll*qpow(2,n-2)*(n-i+1)%Mod)%Mod;
	printf("%d\n",res);
	return 1;
}
void dfs(int u,int sd,int se)
{	if((sd>>(u-1))&1)cnt++;
	vis[u]=1;
	for(int i=f[u];i;i=e[i].nx)
	{	int v=e[i].v,ee=i>>1;
		if(vis[v])continue;
		if((se>>(ee-1))&1)dfs(v,sd,se);
	}
}
bool check(int sd,int se)
{	cnt=0;int sss=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)
		if((sd>>(i-1))&1)sss++;
	for(int i=1;i<=n;i++)
		if((sd>>(i-1))&1){dfs(i,sd,se);break;}
//	if(cnt==sss)return 1;
//	printf("check:\n");
//	for(int u=1;u<=n;u++)if((sd>>(u-1))&1)printf("%d ",u);
//	printf("\n");
//	for(int u=1;u<=m;u++)if((se>>(u-1))&1)printf("e(%d,%d) ",eg[u].u,eg[u].v);
//	printf("\n");
//	printf("cnt:%d (sss=%d)\n",cnt,sss);
	return (cnt==sss);
}
int main()
{	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{	scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		eg[i]=(Edge){u,v},read(u,v),read(v,u);
	}
	if(p1())return 0;
	for(int i=1;i<(1<<n);i++)
		for(int j=0;j<(1<<m);j++)
			if(check(i,j))ans++;
	printf("%d\n",ans);
	return 0;
}
