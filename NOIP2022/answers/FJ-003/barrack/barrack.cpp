#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
constexpr int MOD=1000000007;
int modular_pow(const int& p,const int& q){
	if(q<=0){
		return 1;
	}
	if(q==1){
		return p%MOD;
	}
	int temp=modular_pow(p,q/2);
	ll ans=temp*temp;
	ans%=MOD;
	if(q&1){
		ans*=p;
		ans%=MOD;
	} 
	return ans;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll ans=0;
	ll current;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		current=0;
		current=(n-i)*modular_pow(2,i-1);
		current%=MOD;
		current*=modular_pow(2,m-i);
		current%=MOD;
		ans+=current;
		ans%=MOD; 
	}
	cout<<ans;
	return 0;
}
