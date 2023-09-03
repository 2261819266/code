#include<bits/stdc++.h>
using namespace std;
long long tmp,k,n,a[100001],b[100001],l[100001],r[100001],p,q,i,j,h,g,s,ma=-1,mb=-1;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&tmp,&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	scanf("%lld",&k);
	for(i=1;i<=k;i++)
		scanf("%lld%lld",&l[i],&r[i]);
	for(i=1;i<=k;i++)
		for(j=l[i];j<=r[i];j++)
			for(h=j;h<=r[i];h++)
			{
				p=j,q=h;
				for(g=p;g<=q;g++)
				{
					if(a[i]>ma) ma=a[i];
					if(b[i]>mb) mb=b[i];
					s+=ma*mb;
				}
			}
	printf("%lld",s);

	return 0;
}

