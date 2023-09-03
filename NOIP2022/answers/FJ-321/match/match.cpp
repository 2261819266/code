#include<bits/stdc++.h>
using namespace std;
unsigned long long id,n,q,a[250010],b[250010],ta,tb,l,r,mod=ULLONG_MAX,ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>id>>n;
	for(unsigned long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(unsigned long long i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		for(unsigned long long i=l;i<=r;i++)
		{
			for(unsigned long long j=i;j<=r;j++)
			{
				ta=tb=0;
				for(unsigned long long k=i;k<=j;k++)
				{
					if(a[k]>ta)
					{
						ta=a[k];
					}
					if(b[k]>tb)
					{
						tb=b[k];
					}
				}
				ans=(ans+(ta*tb)%mod)%mod;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
