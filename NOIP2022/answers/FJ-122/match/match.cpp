#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=2.5e5+5;
int a[N],b[N];
signed main()
{
	ios::sync_with_stdio(false);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	cin>>T>>n;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=n;++i) cin>>b[i];
	int Q;
	cin>>Q;
	while (Q--)
	{
		int l,r;
		cin>>l>>r;
		int ans=0;
		for (int p=l;p<=r;++p)
		{
			for (int q=p;q<=r;++q)
			{
				int maxa=0,maxb=0;
				for (int i=p;i<=q;++i) maxa=max(maxa,a[i]),maxb=max(maxb,b[i]);
				ans+=maxa*maxb;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
