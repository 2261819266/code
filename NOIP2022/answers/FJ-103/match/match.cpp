#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
int T,n,a[N],b[N];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);	
	scanf("%d%d",&T,&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++) scanf("%d",&b[i]);
	int q;
	scanf("%d",&q);
	for(int i=1; i<=q; i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ll res=0;
		for(int p=l; p<=r; p++)
			for(int q=p; q<=r; q++)
			{
				int mxa=0,mxb=0;
				for(int i=p; i<=q; i++) mxa=max(mxa,a[i]),mxb=max(mxb,b[i]);
				res=res+(ll)mxa*mxb;
			}
		printf("%lld\n",res);
	}
	return 0;
}

