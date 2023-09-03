#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,q;
int a[3010],b[3010];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	scanf("%d",&q);
	for(int o=1,l,r;o<=q;++o) 
	{
		int ma=-1,mb=-1,ans=0;
		scanf("%d%d",&l,&r);
		for(int p=l;p<=r;++p)
		{
			for(int q=p;q<=r;++q)
			{
				for(int i=p;i<=q;++i)
				{
					ma=max(a[i],ma);
					mb=max(b[i],mb);
				}
				ans+=ma*mb;
			}
		}
		printf("%d",ans);
	 } 
	return 0; 
}
