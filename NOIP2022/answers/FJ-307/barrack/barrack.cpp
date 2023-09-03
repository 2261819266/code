#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007ll,n,ans,an2;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n;ans=(n-1ll)*n/2ll;
	for(int i=1;i<n-1;i++)
		ans=(ans<<1)%mod;
	an2=n;
	for(int i=1;i<n;i++)
		an2=(an2<<1)%mod;
	cout<<(ans+an2)%mod;
	return 0;
}

