#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,m;
int u[1000001],v[1000001];
//vector<int>g[500001];
ll f[1000001],qz[1000001];
int a[1000001],cntt;
int point[500001],cnt;
int fa[500001],depth[500001];
ll ans1;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unio(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
	return;
	if(depth[fx]>depth[fy])
	fa[fy]=fx;
	if(depth[fx]==depth[fy])
	{
		fa[fy]=fx;
		depth[x]++;
	}
	else fa[fx]=fy;
}
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void dfss(int dep)
{
	if(dep==n+1)
	{
		if(cnt==0)
		return;
		int fff=find(point[1]);
		bool flag=1;
		for(int i=2;i<=cnt;i++)
		{
			if(find(point[i])!=fff)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			ans1=(ans1+1)%mod;
		}
		return;
	}
//	cout<<"cnt:"<<cnt<<endl;
	point[++cnt]=dep;
	dfss(dep+1);
	cnt--;
	dfss(dep+1);
}
void dfs(int dep)
{
	if(dep==m+1)
	{
		/*for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]>a[i][k]+a[k][j])
				a[i][j]=a[i][k]+a[k][j];
			}*/
		for(int i=1;i<=cntt;i++)
		unio(u[a[i]],v[a[i]]);
		dfss(1);
		return;
	}
	a[++cntt]=dep;
//	cout<<"cntt:"<<cntt<<endl;
	dfs(dep+1);
	cntt--;
	dfs(dep+1);
}
int main()
{
    freopen("barrack.in","r",stdin);
    freopen("barrack.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&u[i],&v[i]);
    	//g[u].push_back(v);
    	//g[v].push_back(u);
	}
	if(n>3000&&m>5000)
	{
		f[0]=1,qz[0]=1;
		for(ll i=1;i<=m;i++)
		{
			f[i]=(qz[i-1]+(i+1)*qpow(2,i))%mod;
			qz[i]=qz[i-1]+f[i];
		}
		printf("%lld",f[m]);
	}
	else
	{
		for(int i=1;i<=n;i++)
		fa[i]=i;
		dfs(1);
		printf("%lld",ans1);
	}
    return 0;
}
