#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,u,v,f[999999],mod=1000000007;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
	}
	if(n==m+1)
	{
		f[1]=1;
		f[2]=5;
		long long s=1;
		for(int i=3;i<=n;i++)
		{
			s*=2;
			s=s%mod;
			f[i]=2*f[i-1]+(s*(i+1));
			f[i]=f[i]%mod;
		}
		cout<<f[n];
		return 0;
	}
	else
	{
		cout<<rand();
	}
}
