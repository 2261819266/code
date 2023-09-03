#include<bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
long long ans=0;
int pp[1003];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	pp[0]=1;
	for(int i=1;i<=n;i++){
		pp[i]=(pp[i-1]*2)%MOD;
	}
	for(long long len=0;len<=n-1;len++){
		if(len==0){
			ans+=pp[n-1];
			ans%=MOD;
			continue;
		}
		ans+=(((n-len)*pp[len-1]%MOD)*pp[n-1-len])%MOD;
		ans%=MOD;
	}
	cout<<ans;
}
