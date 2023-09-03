#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
const int md = 1000000007;
long long ksm(int q,int k){
	long long res=1,ret=1;
	while(k){
		res*=q;
		res%=md;
		if(k%2) ret*=res,ret%=md;
		k>>=1;
	}
	return ret;
}
int main(){
  freopen("barrack.in","r",stdin);
  freopen("barrack.out","w",stdout);
	cin>>n>>m;
	long long ans=0;
	for(int i=1;i<n;i++){
		ans += i*ksm(2,i-1)*ksm(2,n-i-1);
		ans %= md;
	}
	ans += n*ksm(2,n-1);
	ans %= md;
	cout<<ans;
	return 0;
}
/*
10*2^9+9*(2^0)*2^8+8*(2^1)*2^7+7*(2^2)*2^6+6*(2^3)*2^5+...+2*(2^7)*2^1+1*(2^8)*2^0
*/
