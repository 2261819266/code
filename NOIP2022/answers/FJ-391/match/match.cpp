#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int T,n,a[10001][10001],b[10001][10001],Q,l,r;
ll ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;n++;
	for(int i=1;i<n;i++)
		cin>>a[i][1];
	for(int i=1;i<n;i++)
		cin>>b[i][1];
	for(int j=2;j<n;j++)
		for(int i=1;i<n;i++)
			a[i][j]=max(a[i-1][j-1],a[i][j-1]),b[i][j]=max(b[i-1][j-1],b[i][j-1]);
	cin>>Q;
	while(Q--)
	{
		cin>>l>>r;ans=0;
		for(int p=l;p<=r;p++)
			for(int q=l;q<=p;q++)
				ans+=a[p][p-q+1]*b[p][p-q+1];
		cout<<ans<<endl;
	}
}
