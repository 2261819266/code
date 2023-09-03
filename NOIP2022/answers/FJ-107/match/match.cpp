#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5e4+5;
int id,n,q,a[N],b[N];
int maxna[3005][3005],maxnb[3005][3005];
unsigned long long f[3005][3005],ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>id>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int l,r;
	for(int i=1;i<=n;i++){
		maxna[i][i]=a[i];
		maxnb[i][i]=b[i];
		for(int j=1;j<i;j++){
			maxna[j][i]=max(maxna[j][i-1],a[i]);
			maxnb[j][i]=max(maxnb[j][i-1],b[i]);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		ans=0;
		for(int j=l;j<=r;j++){
			for(int k=j;k<=r;k++)
				ans+=(long long)maxna[j][k]*maxnb[j][k];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
