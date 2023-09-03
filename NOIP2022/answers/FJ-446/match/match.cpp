#include <bits/stdc++.h>
using namespace std;
int t,n,q,l,r,maxx,a[250010],b[250010],maxa[10010][10010],maxb[10010][10010];
unsigned long long mod=18446744073709551615,ans=0;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    cin>>t>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa[i][i]=a[i];
	}
    for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		maxb[i][i]=b[i];
	}
    for(int i=1;i<=n-1;i++)
    {
    	maxx=a[i];
    	for(int j=i+1;j<=n;j++)
    	{
    		maxx=max(maxx,a[j]);
    		maxa[i][j]=maxx;
		}
	}
	for(int i=1;i<=n-1;i++)
	{	
	    maxx=b[i];
		for(int j=i+1;j<=n;j++)
		{
			maxx=max(maxx,b[j]);
			maxb[i][j]=maxx;
		}
	}
	cin>>q;
	while(q--)
	{
		ans=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			for(int j=i;j<=r;j++)
			{
				ans=(ans+maxa[i][j]*maxb[i][j])%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
