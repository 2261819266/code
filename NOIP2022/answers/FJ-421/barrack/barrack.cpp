#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		int k=i+1;
		for(int j=i;j>=1;j--)
		{
			k=k*2%mod;
		}
		ans=ans+k%mod;
	}
	cout<<ans<<endl;
	return 0;
}

