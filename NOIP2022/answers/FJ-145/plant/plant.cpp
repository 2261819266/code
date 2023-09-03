#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,m,C,F,Test_num,id;
LL ansc,ansf,res;
LL f[1002][1002],g[1002][1002];
char s[1002][1002];
inline void solve()
{
	scanf("%d%d%d%d",&n,&m,&C,&F),ansc=ansf=0;
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			f[i][j]=g[i][j]=1;
	//Find R
	for(int i=1;i<=n;++i)
		for(int j=m,t=m+1;j;--j)
		{
			if(s[i][j]=='1')t=j;
			(f[i][j]*=max(t-j-1,0))%=mod,(g[i][j]*=max(t-j-1,0))%=mod;
		}
	//Find D
	for(int j=1;j<=m;++j)
		for(int i=n,t=n+1;i;--i)
		{
			if(s[i][j]=='1')t=i;
			(g[i][j]*=max(t-i-1,0))%=mod;
		}
	for(int j=1;j<=m;++j)
	{
		res=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i][j]=='1')res=0;
			(ansc+=f[i][j]*res)%=mod;
			(ansf+=g[i][j]*res)%=mod;
			if(i>1 && s[i][j]=='0')(res+=f[i-1][j])%=mod;
		}
	}
	printf("%lld %lld\n",(ansc*C)%mod,(ansf*F)%mod);
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&Test_num,&id);
	for(;Test_num--;)solve();
	return 0;
}
