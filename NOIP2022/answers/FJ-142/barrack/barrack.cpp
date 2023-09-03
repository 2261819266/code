#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long n,ans=1,c=1;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++)
	  ans+=i*n,ans%=mod;
	printf("%lld\n",ans);
	return 0;
}
