#include<bits/stdc++.h>
using namespace std;
const int N=2.5e5+10;
unsigned long long res[N];
int a[N],b[N],n,m;
int sta[N],tpa,stb[N],tpb;
int main()
{
	int T;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		unsigned long long ans=0;
		for(int i=l;i<=r;++i)
			for(int j=i;j<=r;++j)
			{
				int ma=0,mb=0;
				for(int t=i;t<=j;++t)
					ma=max(ma,a[t]),mb=max(mb,b[t]);
				ans+=(unsigned long long)ma*mb;
			}
		printf("%llu\n",ans);
	}
	return 0;
}
