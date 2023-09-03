#include<bits/stdc++.h>
using namespace std;
int t,n,Q,l,r,biga,bigb;
long long ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		ans=0;
		cin>>l>>r;
		for(int p=l;p<=r;p++)
		{
			for(int q=p;q<=r;q++)
			{
				biga=-1;
				bigb=-1;
				for(int j=p;j<=q;j++)
				{
					if(a[j]>biga)biga=a[j];
					if(b[j]>bigb)bigb=b[j];
				}
				ans+=biga*bigb;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}