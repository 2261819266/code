#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	cin>>T>>n;
	int cnt[n+1],cnt1[n+1];
	int flag[n+1][n+1];
	memset(flag,0,sizeof(flag));
	cnt[0]=0,cnt1[0]=0;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[i]=max(cnt[i-1],a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		cnt1[i]=max(cnt1[i-1],b[i]);
	}
	int ans=0;
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=r;j++)
			{
				int anss=0,ansss=0;
				for(int k=min(i,j);k<=max(i,j);k++)
				{
					anss=max(anss,a[k]);
					ansss=max(ansss,b[k]);
				}
				if(flag[anss][ansss]!=1)
				{
					ans+=(unsigned long long)(anss*ansss);
					flag[anss][ansss]=1;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

