#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n,l,r,p,q,z,sum;
int m[MAXN],o[MAXN],ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>m[i];
	for(int i=1;i<=n;i++) cin>>o[i];
	cin>>z;
	int a,b;
	for(int i=1;i<=z;i++)
	{
		cin>>l>>r;
		ans=0;
		sum=0;
		for(p=l;p<=r;p++)
		{
			for(q=p;q<=r;q++)
			{
				sum=max(sum,m[p]*o[q]);
			}
			ans+=sum;
		}
		cout<<ans<<endl;
	}
	return 0;
}