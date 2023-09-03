#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=1<<32+1<<32;
unsigned long long t,q,l,r,n,a[250005],b[250005],xxx[100];
unsigned long long maxa[3005][3005],maxb[3005][3005],ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&t,&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		maxa[i][i]=a[i],maxb[i][i]=b[i];
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			maxa[i][j]=max(maxa[i][j-1],a[j]),
			maxb[i][j]=max(maxb[i][j-1],b[j]);
	scanf("%lld",&q);
	while(q--){
		ans=0;
		scanf("%lld%lld",&l,&r);
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++){
				ans=ans+1ll*maxa[i][j]*maxb[i][j];
			}
		printf("%lld\n",ans);
	}
	return 0;
}
