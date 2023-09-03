#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned long long a[250010]={0},b[250010]={0};
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("match.in","r",stdin);freopen("match.out","w",stdout);
	int t1,n;cin>>t1>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int q1;cin>>q1;
	while(q1--)
	{
		int l,r;unsigned long long ans=0;cin>>l>>r;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++)
			{
				int ma=0,mb=0;
				for(int i=p;i<=q;i++)
				{
					if(a[i]>ma)ma=a[i];
					if(b[i]>mb)mb=b[i];
				}
				ans=ans+ma*mb;
			}
		cout<<ans<<endl;
	}
	return 0;
}
