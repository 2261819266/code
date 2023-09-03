//10
#include<bits/stdc++.h>
#define yu 1000000007
#define ll long long 
using namespace std;
ll ksm(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1)
		{
			c*=a;
			c%=yu;
		}
		b>>=1;
		a*=a;
		a%=yu;
	}
	return c;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
	}
	ll ans=0;
	if(n==m+1)
	{
		for(int i=1;i<=n;i++)
		{
			int yb=n-i,yd=max(0,i-2);
			ans+=(n-i+1)%yu*(ksm(2,yb)*ksm(2,yd))%yu;
			ans%=yu;
		}		
	}
	else if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			int yb=n-i,yd=max(0,i-2);
			ans+=(n-i+2)%yu*(ksm(2,yb)*ksm(2,yd))%yu;
			ans%=yu;
		}			
	}
	cout<<ans;
	return 0;
}
