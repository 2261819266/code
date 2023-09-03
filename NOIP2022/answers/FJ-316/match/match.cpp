#include<bits/stdc++.h>
using namespace std;
unsigned long long mod=pow(2,64);
int t,n,a[260000],b[260000],q,l,r,maxx,maxn;
long long ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)	
		scanf("%d",&b[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
		{
			for(int k=j;k<=r;k++)
			{
				maxx=max(maxx,a[k]),maxn=max(maxn,b[k]);
				ans=(ans+(maxx*maxn)%mod)%mod;
			}
			maxx=maxn=0;
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
