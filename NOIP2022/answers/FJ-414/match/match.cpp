#include<bits/stdc++.h>
using namespace std;
int t,n,a[250010],b[250010],l,r,Q;
unsigned long long mod=1145141919810;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		long long ans=0;
		scanf("%d%d",&l,&r);
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				int maxa=0,maxb=0;
				for(int j=p;j<=q;j++){
					maxa=max(maxa,a[j]);
					maxb=max(maxb,b[j]);
				}
				ans+=(maxa*maxb)%mod;
			}
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	
}

