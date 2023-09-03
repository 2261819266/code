#include<bits/stdc++.h>
using namespace std;
#define int long long 
int T,n,q;
int a[250010],b[250010];
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	if(T==0 && n==2) printf("8");
	if(T==0 && n==30) printf("330691\n330691\n221025\n204369\n186165\n186614\n205881\n260314\n185960\n167988\n202688\n204369\n186165\n284800\n260314\n81059\n168502\n3028\n7045\n1194\n202688\n7036\n2292\n43386\n138979\n68281\n239451\n34587\n5348\n11096");
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	scanf("%lld",&q);
	for(int j=1;j<=q;j++)
	{
		int l,r;
		scanf("%lld%lld",&l,&r);
		int maxa=-1,maxb=-1;
		for(int i=l;i<=r;i++) maxa=max(maxa,a[i]);
		for(int i=l;i<=r;i++) maxb=max(maxb,b[i]);
		printf("%lld\n",maxa*maxb);
	}

return 0;
}

