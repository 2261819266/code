#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	long long sum[10001],ans=0;
	int k;
	sum[0]=1;
	for(int i=1;i<=n;i++){
		k=n-i+1;
		sum[i]=sum[i-1]*k;
		sum[i]%=1000000007;
	}
	ans=sum[1]*2;
	for(int i=2;i<=n;i++){
		ans=sum[i]+ans;
		ans%=1000000007;
	}
	cout<<ans;
	
	return 0;
}
