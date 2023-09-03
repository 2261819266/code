#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod=4611686018427387904;
int a[300005],b[300005];
int st1[300005][20],st2[300005][20];
int ans;
int s1(int l,int r)
{
	int mlog=log2(r-l);
	return max(st1[l][mlog],st1[r-(1<<mlog)+1][mlog]);
}int s2(int l,int r)
{
	int mlog=log2(r-l);
	return max(st2[l][mlog],st2[r-(1<<mlog)+1][mlog]);
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int t,n;
	cin>>t>>n;
	//cout<<mod;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		st1[i][0]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		st2[i][0]=b[i];
	}
	for(int i=1;i<=18;i++)
		for(int j=1;j<=n;j+=(1<<i))
		{
			st1[j][i]=max(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
			st2[j][i]=max(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
			//cout<<st1[j][i]<<endl;
			//cout<<st2[j][i]<<endl;
		}
		
	int k;
	cin>>k;
	while(k--)
	{
		int l,r;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++)
			{
				ans=ans+s1(i,j)*s2(i,j)%mod;
			}
		cout<<ans<<endl;
	}
	return 0;
}
