#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m;
ll ans=0,jc[500005]={1},tmp,f;

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin>>n>>m;
	if(m==n-1){
		ll res=1;
		for(int i=1;i<=n;i++){
			res=res*i%mod; jc[i]=res;
		}
		for(int i=1;i<=n;i++){
			tmp=n-i+1;
			for(int j=1;j<=n-i;j++){
				f=f+(jc[m]/(jc[j]*jc[m-j]));
			}
			ans=(ans+tmp*f%mod+1)%mod;
		}
		cout<<ans;
	}
	
	return 0;
}

