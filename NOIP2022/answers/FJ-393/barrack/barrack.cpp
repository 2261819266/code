#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long ans=0;
int n,m;
long long t[500005];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	if(m==n-1){
		t[1]=1;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=2;j--){
				t[j]+=t[j-1];
			}long long res=1;
			long long a=2;
			int k=i-1;
			for(;k;k>>=1,a=(a*a)%mod){
				if(k&1)	res=(res*a)%mod;
			}t[1]=res*i%mod;
			t[i]=1;
		}for(int i=1;i<=n;i++){
			ans=(ans+t[i])%mod;
		}cout<<ans<<endl;
	}else{
		ans=n*(n+1)%mod;
		ans--;
		long long res=1;
		long long a=2;
		n++;
		for(;n;n>>=1,a=(a*a)%mod){
			if(n&1)	res=(res*a)%mod;
		}cout<<(ans+res)%mod<<endl;
	}return 0;
}
