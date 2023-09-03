#include<bits/stdc++.h>
using namespace std;
#define file(in,out) freopen(in,"r",stdin);\
					 freopen(out,"w",stdout);
#define ll long long
#define ull unsigned long long
#define rint register int
#define mod  1000000007
ull qpow(ll n,ll num)
{
	ull base=n,ans=n;
	while(num!=1)
	{
		if(num&1)ans=ans*base%mod;
		
		ans=ans*base%mod;base=base*base%mod;
		num>>=1;
	}
	return ans;
}
int main()
{
	int n,m;
	file("barrack.in","barrack.out");
	cin>>n>>m;
	cout<<qpow(2,n)+1<<endl;
	return 0;
}
