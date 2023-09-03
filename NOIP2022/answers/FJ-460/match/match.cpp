#include<bits/stdc++.h>
using namespace std;
int a[1000001],b[1000001],n,q,l,r,t;
long long ans;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		for(int j=l;j<=r;j++)
		{
			for(int k=l;k<=r;k++)ans+=(a[i]*a[j])%10000007;
		}
	}
	cout<<ans<<endl;
	return 0;
}