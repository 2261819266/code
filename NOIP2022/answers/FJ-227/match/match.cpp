#include <bits/stdc++.h>
using namespace std;
long long t,n,q;
long long a[250005],b[250005];
const long long p=pow(2,64);
long long maxn_a(long long l,long long r,long long ans){
	for(int i=l;i<=r;i++){
		ans=max(ans,a[i]);
	}
	return ans;
}
long long maxn_b(long long l,long long r,long long ans){
	for(int i=l;i<=r;i++){
		ans=max(ans,b[i]);
	}
	return ans;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&t,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	scanf("%lld",&q);
	for(int i=1;i<=q;i++){
		long long l,r,ans=0;
		scanf("%lld%lld",&l,&r);
		for(int j=l;j<=r;j++){
			for(int k=l;k<=r;k++){
				ans+=maxn_a(j,k,0)*maxn_b(j,k,0);
			}
		}
		printf("%lld",ans%p);
	}
	return 0;
}
