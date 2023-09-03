#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define ull unsigned long long
using namespace std;
ull t,n,q,a[1000001],b[1000001],l,r,ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for (ull i=1;i<=n;i++) cin>>a[i];
	for (ull i=1;i<=n;i++) cin>>b[i];
	cin>>q;
	while (q--)
	{
		ans=0;
		cin>>l>>r;
		for (ull i=l;i<=r;i++)
		{
			ull maxa=a[i],maxb=b[i];
			for (ull j=i;j<=r;j++)
			{
				maxa=max(a[j],maxa);
				maxb=max(b[j],maxb);
				ans+=maxa*maxb;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
