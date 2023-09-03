#include<bits/stdc++.h>
#define Re register
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=250005;

int T,n,q;

ll a[N],b[N];

ull ans=0;

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(Re int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(Re int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	scanf("%d",&q);
	while(q--)
	{
		ans=0;
		int l,r;
		scanf("%d%d",&l,&r);
		ll mxa=0ll,mxb=0ll;
		for(Re int i=l;i<=r;i++)
		{
			for(Re int j=i;j<=r;j++)
			{
				mxa=mxb=0ll;
				for(Re int k=i;k<=j;k++)
				{
					mxa=max(mxa,a[k]);
					mxb=max(mxb,b[k]);
				}
				ans=(ull)ans+1ll*mxa*mxb;
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
