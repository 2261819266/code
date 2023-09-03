//NOIP2022 RP++!
//in:barrack.in
//out:barrack.out
//Let us go!
#include <iostream>
#include <cstdio>
#define MOD 1000000007
#define ll long long
using namespace std;
ll power(ll x,ll y){
	if(y==0) return 1;
	ll res=1;
	while(y){
		if(y&1) res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}
int n;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	ll ans=0;
	for(int i=1;i<n;i++) ans=(ans+(n-i+1)*power(2,n-i)%MOD)%MOD;
	ans++;
	cout<<ans;
	return 0;
}
//15pts
