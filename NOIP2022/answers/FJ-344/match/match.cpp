#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int n,q;
int a[N],b[N];
typedef unsigned long long ull;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%*d%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=1;i<=n;i++) scanf("%d",b+i);
	scanf("%d",&q);
	while (q--)
	{
		int l,r;
		ull ans=0;
		scanf("%d%d",&l,&r);
		for (int i=l;i<=r;i++)
			for (int j=i;j<=r;j++)
			{
				int mx1=0,mx2=0;
				for (int k=i;k<=j;k++) mx1=max(mx1,a[k]);
				for (int k=i;k<=j;k++) mx2=max(mx2,b[k]);
//				cout<<mx1<<" "<<mx2<<endl;
				ans+=(ull)mx1*mx2;
//				cout<<(ull)mx1*mx2<<endl;
			}
//		cout<<ans<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}
