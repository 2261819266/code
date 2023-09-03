#include<bits/stdc++.h>
using namespace std;
long long t,n,m,a[300000],b[300000],c[99],l,r,p,sum;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&t,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=63;j++) c[j]=0;
		scanf("%lld%lld",&l,&r);
		for(int j=l;j<=r;j++)
		{
			sum=a[j]*a[j]*(j-l+1);
			p=0;
			while(sum)
			{
				if(sum%2==1) c[p]++;
				if(c[p]>=2)
				{
					c[p+1]+=c[p]/2;
					c[p]=c[p]%2;
				}
				sum=sum>>1;
				p++;
			}
		}
		p=1,sum=0;
		if(c[0]==1) sum++;
		for(int j=1;j<=63;j++)
		{
			p*=2;
			if(c[j]) sum+=p;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
