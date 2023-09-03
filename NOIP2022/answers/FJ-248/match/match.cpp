#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;
	int n,q,p,Q,zi;
	int a[250001],b[250001];
	int l[250001],r[250001];
	int cha[250001],chb[250001];
	long long ans=0;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		scanf("%d %d",&l[i],&r[i]);
	}
	for(int i=1;i<=Q;i++)
	{
		ans=0;
		for(p=l[i];p<=r[i];p++)
		{
			for(q=p;q<=r[i];q++)
			{
				zi=0;
				for(int z=p;z<=q;z++)
				{
					cha[zi]=a[z];
					chb[zi]=b[z];
					zi++;
				}
				sort(cha,cha+zi);
				sort(chb,chb+zi);
				ans+=cha[zi-1]*chb[zi-1];
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
