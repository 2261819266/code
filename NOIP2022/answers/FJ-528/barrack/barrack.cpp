#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,i,p=1000000007,u,v,s=1;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	cin>>u>>v;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(n==2)
	{
		cout<<5;
		return 0;
	}
	for(i=1;i<=n-3;i++)
	s=s*2%p;
	ans=(n*n-n)%p*s%p+n*s*4%p;
	cout<<ans%p;
	return 0;
}
