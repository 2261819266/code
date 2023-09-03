#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int n,m,u,v;
int h[500001];
int cnt;
ll ans;
ll c[1000001];
struct node
{
	int to;
	int mynext;
}e[1000001];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].mynext=h[x];
	h[x]=cnt;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	c[0]=1;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		c[i]=c[i-1]*i%mod;
	}
	//选一个城市的方案数 
	ans=(n*c[m])%mod;
	printf("%lld",(ans*n/2+2)%mod);
	return 0;
}
	
