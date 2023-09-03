#include<iostream>
#include<cstdio>
using namespace std;
long long mod=1e9+7;
int main( ){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		
	}
	long long p=1;
	long long ans=0;
	for(long long i=n-1;i>=1;i--){
		ans+=i*p%mod;
		p*=2;
		p%=mod;
	}
	ans+=p*n%mod;
	ans%=mod;
	cout<<ans;
	return 0;
}
