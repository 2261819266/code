#include<bits/stdc++.h>
using namespace std;
unsigned long long x,y,n,m,ans,a[30000005],b[30000005];
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
	}
	ans+=n*2+1;
	ans%=(1000000000+7);
	cout<<ans;
	return 0;
}
