#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=5e5+10;
int n,m;
inline long long qpower(int x)
{
	long long ans=1,res=1;
	while(x){
		if(x&1) ans=res%mod*ans%mod;
		res=res%mod*res%mod;
		x>>=1;
	}
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	cin>>n>>m;
	long long all=(qpower(n)%mod-1)*(qpower(m)%mod)%mod;
	cout<<all<<endl;
}
