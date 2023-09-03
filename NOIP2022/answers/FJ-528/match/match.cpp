#include<bits/stdc++.h>
using namespace std;
long long i,j,a[3005],b[3005],n,q,T,ans,l,r,m1,m2;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	cin>>b[i];
	cin>>q;
	while(q--)
	{
		ans=0;
		cin>>l>>r;
		for(i=l;i<=r;i++)
		{
			m1=m2=0;
			for(j=i;j<=r;j++)
			{
				m1=max(m1,a[j]);
				m2=max(m2,b[j]);
				ans+=m1*m2;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

