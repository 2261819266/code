#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,u,v1,ans;
vector<int>v[500500];
long long fast_power(int b)
{
	long long a=2,ans=1;
	while(b)
	{
		if(b&1)	ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;	
	}	
	return ans;
}
int C(int a,int b)
{
	int sum1=1,sum2=1;
	for(int i=1;i<=b;i++)
		sum2=(sum2*i)%mod;
	for(int i=a;i>=a-b+1;i--)
		sum1=(sum1*i)%mod;
	return sum1/sum2;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v1),v[u].push_back(v1),v[v1].push_back(u);
	ans=(n*fast_power(m))%mod;
	for(int i=2;i<=n;i++)
		ans=(ans+(C(n,i)*fast_power(m-i+1))*n%mod)%mod;
	cout<<ans;
	return 0;
}
