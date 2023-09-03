#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int T,n,q,l,r;
ull ans,ma,mb,a[250000],b[250000],sum[3010][3010][2];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%llu",&a[i]);
	for(int i=1;i<=n;i++) scanf("%llu",&b[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ma=mb=0;
			for(int k=i;k<=j;k++)
			{
				if(a[k]>ma) ma=a[k];
				if(b[k]>mb) mb=b[k];
			}
			sum[i][j][0]=ma;sum[i][j][1]=mb;
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		ans=0;
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++)
				ans+=sum[i][j][0]*sum[i][j][1];
		printf("%llu\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
