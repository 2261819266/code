#include <bits/stdc++.h>
using namespace std;
int t,n,a[250005],b[250005],q,w,e,mx1,mx2,f[250005][18],r[250005][18];
unsigned long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++)cin>>b[i];
	cin>>q;
		while(q--){
			scanf("%d%d",&w,&e);
			ans=0;
			for(int i=w; i<=e; i++){//w...e
				mx1=mx2=0;
				for(int j=i; j<=e; j++){
					mx2=max(mx2,b[j]);
					mx1=max(mx1,a[j]);
					ans=(ans+1ll*mx1*mx2);
				}
			}
			printf("%lld\n",ans);
		}
	return 0;
}
