#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const ll N=2.5*1e5;
ll T,n,Q;
ll a[N],b[N],l,r,amax,bmax;
ull ans=0;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	cin>>Q;
	while(Q--)
	{
		ans=0;
		amax=-1,bmax=-1;
		cin>>l>>r;
		for(int p=l;p<=r;p++)
		{
			for(int q=p;q<=r;q++)
			{
				amax=-1,bmax=-1;
				for(int i=p;i<=q;i++)
				{
					amax=max(amax,a[i]);
					bmax=max(bmax,b[i]);
				}
				ans+=amax*bmax;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

