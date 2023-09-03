#include<bits/stdc++.h>
#define in inline
#define ll long long int
#define rll register ll
using namespace std;
ll fac[100001];
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
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	ll n=read(),m=read();
	if(m==n-1)
	{
		fac[1]=1;
		for(rll i=2;i<=n;i++)
		fac[i]=(fac[i-1]*i)%1000000007;
		ll ans=n*m*2;
		for(rll i=1;i<=m;i++)
		{
			if(i<=2)
			ans=(ans+i*(m-i+1))%1000000007;
			else
			ans=(ans+i*(m-i+1)*fac[i-2])%1000000007;
		}
		print(ans);
	}
	return 0;
}
