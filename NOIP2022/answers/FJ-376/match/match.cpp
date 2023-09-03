#include<cstdio>
#include<algorithm>
#define re register
#define ull unsigned long long
const int N=3e3+3;
int T,n,q,a[N],b[N];
ull ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(re int i=1;i<=n;++i) scanf("%d",a+i);
	for(re int i=1;i<=n;++i) scanf("%d",b+i);
	scanf("%d",&q);
	for(re int l,r,c,d;q--;)
	{
		scanf("%d%d",&l,&r),ans=0;
		for(re int i=l;i<=r;++i)
			for(re int j=i;j<=r;++j)
			{
				c=d=0;
				for(re int k=i;k<=j;++k)
					c=std::max(c,a[k]),d=std::max(d,b[k]);
				ans+=1ull*c*d;
			}
		printf("%llu\n",ans);
	}
	return 0;
}
