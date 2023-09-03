#include<bits/stdc++.h>
using namespace std;
long long t,n,q,l,r;
long long a[250005],b[250005];
long long ans;
long long fin(int j,int k)
{
	long long maxa=-1;
	for(int i=j;i<=k;i++)
		maxa=max(maxa,a[i]);
	long long maxb=-1;
	for(int i=j;i<=k;i++)
		maxb=max(maxb,b[i]);
	return maxa*maxb;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		for(int j=l;j<=r;j++)
			for(int k=j;k<=r;k++)
				ans+=fin(j,k);	
		cout<<ans<<"\n";
	}
	return 0;
}