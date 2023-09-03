#include<bits/stdc++.h>
using namespace std;
int t,n,q,l,r;
long long a[250100],b[250100];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	scanf("%d",&q);
	while(q--){
		long long ans=0,maxa=0,maxb=0;
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				maxa=0;
				maxb=0;
				for(int k=i;k<=j;k++){
					maxa=max(maxa,a[k]);
					maxb=max(maxb,b[k]);
				}
				ans+=maxa*maxb;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
