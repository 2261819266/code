#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
long long pre=1,ans=0,mod=1000000007;
int find(int h){
	if(h==n)return 1;
	int sum=1;
	for(int i=1;i<=min(h,n-h);++i)sum=sum*(n-i+1)/i%mod;
	return sum%mod;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;--i){
		int k=find(i)%mod;
		k=k*pre%mod;
		ans=(ans+k)%mod;
		pre*=2;
		pre%=mod;
	}
	cout<<ans%mod;
	return 0;
}
//=0
