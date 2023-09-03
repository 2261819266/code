#include<bits/stdc++.h>
using namespace std;
long long t,q,n,l,r,a[10001],b[10001],f1[5001][5001],f2[5001][5001];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(long long i=1;i<=n;i++)
	{
		f1[i][i]=a[i];
		f2[i][i]=b[i];
	}
	for(long long l=2;l<=n;l++)
	{
		for(long long i=1;i+l-1<=n;i++)
		{
			long long j=i+l-1;
			f1[i][j]=max(f1[i][(i+j)/2],f1[((i+j)/2)+1][j]);
			f2[i][j]=max(f2[i][(i+j)/2],f2[((i+j)/2)+1][j]);
		}
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		unsigned long long ans=0;
		for(long long i=l;i<=r;i++)
		{
			for(long long j=i;j<=r;j++)
			{
				ans+=(f1[i][j]*f2[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
