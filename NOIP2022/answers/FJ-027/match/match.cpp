#include<bits/stdc++.h>
#define N 250010
using namespace std;
int T,n,Q;
unsigned long long a[N],b[N],ans;
int main() 
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i) scanf("%llu",a+i);
	for(int i=1;i<=n;++i) scanf("%llu",b+i);
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		for(int p=l;p<=r;++p)
		{
			for(int q=p;q<=r;++q)
			{
				unsigned long long max1=0,max2=0;
				for(int i=p;i<=q;++i)
				{
					max1=max(max1,a[i]);
					max2=max(max2,b[i]);
				}
				ans+=max1*max2;
			}
		}
	}
	printf("%llu\n",ans);
	return 0;
}
