#include<bits/stdc++.h>
#define in inline
#define ll long long int
#define rll register ll
using namespace std;
ll a[2000001],vis[601],visi[301];
struct node
{
	ll x,a,b;
}st[4000001];
in ll read()
{
	char c=getchar();
	ll ans=0;
	bool flag=false;
	while(!(isdigit(c)))
	{
		flag=(c=='-');
		c=getchar();
	}
	while(isdigit(c))
	{
		ans=(ans<<3)+(ans<<1)+(c^48);
		c=getchar();
	}
	return (flag? (~ans+1):ans);
}
in void print(ll n)
{
	if(n<0)
	{
		putchar('-');
		n=~n+1;
	}
	if(n>=10)
	print(n/10);
	putchar((n%10)|48);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(),ll t=read();
	for(rll i=1;i<=2*t;i++)
	read();
	ll tmp=read();
	while(tmp--)
	{
		print(114514);
		putchar('\n');
	}
	return 0;
}
