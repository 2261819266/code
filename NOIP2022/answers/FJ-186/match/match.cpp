#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
const int maxn=250010;
ll t,n,Q,l,r,ans,ma,mb;
ll a[maxn],b[maxn];

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);			 cout.tie(0);
	
	cin>>t>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		cin>>b[i];
	cin>>Q;
	while(Q--)
	{
		ans=0;
		cin>>l>>r;
		for(ll p=l;p<=r;p++)
		{
			ma=a[p],mb=b[p];
			for(ll q=p;q<=r;q++)
			{
				ma=max(ma,a[q]);
				mb=max(mb,b[q]);
				ans+=ma*mb;
			}
		}
		cout<<ans<<"\n";
	}	
	
	return 0;
}
