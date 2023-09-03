#include<bits/stdc++.h>
using namespace std;
long long T,n,a[250005],b[250005],Q;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)scanf("%lld",&b[i]);
	scanf("%lld",&Q);
	while(Q--){
		long long l,r,ans=0;
		scanf("%lld%lld",&l,&r);
		for(int i=l;i<=r;++i)
		    for(int j=i;j<=r;++j){
		    	long long maxa=0,maxb=0;
		    	for(int k=i;k<=j;++k){
		    		maxa=max(maxa,a[k]);
		    		maxb=max(maxb,b[k]);
				}
				ans=ans+maxa*maxb;
			}
		cout<<ans<<endl;
	}
	return 0;
}
//=0
