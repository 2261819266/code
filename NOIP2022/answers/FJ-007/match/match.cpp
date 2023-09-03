#include<bits/stdc++.h>
using namespace std;
const int Q=2.5e5+10;
typedef unsigned long long ull;
ull a[Q],b[Q],q,n,ans,amax,bmax,T,l,r;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%llu%llu",&T,&n);
	for(ull i=1;i<=n;i++)
	{
		scanf("%llu",&a[i]);
	}
	for(ull i=1;i<=n;i++)
	{
		scanf("%llu",&b[i]);
	}
	scanf("%llu",&q);
	while(q--)
	{
		scanf("%llu%llu",&l,&r);
		for(ull i=l;i<=r;i++)
		{
			amax=a[i],bmax=b[i];
			for(ull j=i;j<=r;j++)
			{
				amax=max(amax,a[j]);
				bmax=max(bmax,b[j]);
				ans+=amax*bmax; 
			}
		}
		printf("%llu",ans);
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
