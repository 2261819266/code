#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
long long mm=1e9+7,n,m,ans;
long long wdnmd(long long a)
{
	long long b=2,c=1;
	while(c*2<a)
	{
		b=((b%mm)*(b%mm))%mm;
		c*=2;
	}
	for( int i=a-c;i>=1;i--)
	{
		b*=2;
		b%=mm;
	}
	return b;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for( int i=0;i<=m;i++)
	{
		ans=ans+((wdnmd(i))*(i+1))%mm;
		ans%=mm;
	}
	cout<<ans;
	return 0;
}
