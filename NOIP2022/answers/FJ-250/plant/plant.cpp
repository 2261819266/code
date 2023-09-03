#include<cstdio>
typedef long long ll;
const ll SIZE=3010,mod=998244353;
inline ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x*10)+(ch^48),ch=getchar();
	return x;
}
inline void readstr(bool arr[])
{
	int top=0;char ch=getchar();
	while(ch<'0'||ch>'1')ch=getchar();
	while(ch>='0'&&ch<='1')arr[++top]=ch-'0',ch=getchar();
}
ll T,id,n,m,c,f,sum[SIZE][SIZE],r[SIZE][SIZE],dn[SIZE][SIZE];
bool mp[SIZE][SIZE];
inline ll getc()
{
	ll res=0;
	for(int i=3;i<=n;i++)for(int j=1;j<=m;j++)if(!mp[i-1][j])res=(res+sum[i-2][j]*r[i][j])%mod;
	return res;
}
inline ll getf()
{
	ll res=0;
	for(ll i=3;i<=n;i++)for(ll j=1;j<=m;j++)if(!mp[i-1][j])res=(res+(sum[i-2][j]*r[i][j])%mod*dn[i][j])%mod;
	return res;
}
inline void solve()
{
	n=read(),m=read(),c=read(),f=read();
	for(ll i=1;i<=n;i++)readstr(mp[i]);
	for(ll i=1;i<=n;i++)for(ll j=m;j;j--)if(!mp[i][j])r[i][j]=r[i][j+1]+1;
	for(ll j=1;j<=m;j++)for(ll i=n;i;i--)if(!mp[i][j])dn[i][j]=dn[i+1][j]+1;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)if(!mp[i][j])r[i][j]--,dn[i][j]--;
	for(ll j=1;j<=m;j++)for(ll i=1;i<=n;i++)if(!mp[i][j])sum[i][j]=(sum[i-1][j]+r[i][j])%mod;
	printf("%lld %lld\n",c*getc(),f*getf());
}
int main()
{
	freopen("plant.in","r",stdin),freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--)solve();
	return 0;
}
