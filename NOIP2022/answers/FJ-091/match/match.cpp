#include<cstdio>
#include<iostream>
using namespace std;
int id,n,a[100005],b[100005],q,l,r;
int main()
{
	freopen("match","r",stdin);
	freopen("match","w",stdout);
	scanf("%d%d",&id,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=1;j<=n;j++)
	{
		scanf("%d",&b[j]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		unsigned long long ans=0;
		scanf("%d%d",&l,&r);
		int maxa=0,maxb=0;
		for(int j=l;j<=r;j++)
		{
			for(int k=j;k<=r;k++)
			{
				maxa=0,maxb=0;
				for(int a1=j;a1<=k;a1++)
				{
					maxa=max(maxa,a[a1]);
				}
				for(int b1=j;b1<=k;b1++)
				{
					maxb=max(maxb,b[b1]);
				}
				ans+=maxa*maxb;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
