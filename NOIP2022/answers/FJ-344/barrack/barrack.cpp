#include <bits/stdc++.h>
using namespace std;
int n,m,mod=1e9+7,two[500005],ans;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","r",stdout);
	cin>>n>>m;
	two[0]=1;
	for (int i=1;i<=n;i++) two[i]=two[i-1]*2%mod;
	if (n==m)
	{
		for (int i=1;i<=n;i++)
		{
			ans=(ans+(long long)(n-i+1)*two[max(0,i-2)]%mod*two[n-i+1]%mod)%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		ans=(ans+(long long)(n-i+1)*two[max(0,i-2)]%mod*two[n-i]%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
