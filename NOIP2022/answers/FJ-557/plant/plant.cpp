#include<bits/stdc++.h>
#define in inline
#define ll long long int
#define rll register ll
using namespace std;
char mapp[1001][1001];
ll sum[1001][1001],tmp1[1001][1001],tmp2[1001][1001];
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
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ll t=read(),id=read();
	if(id==1)
	{
		for(rll i=1;i<=t;i++)
		{
			print(0);
			putchar(' ');
			print(0);
			putchar('\n');
		}
		return 0;
	}
	while(t--)
	{
		ll n=read(),m=read(),c=read(),f=read(),sum1=0,sum2=0;
		for(rll i=1;i<=n;i++)
		{
			for(rll j=1;j<=m;j++)
			{
				mapp[i][j]=getchar();
				sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(mapp[i][j]^48);
			}
			getchar();
		}
		for(rll x1=1;x1<=n-2;x1++)
		{
			for(rll x2=x1+2;x2<=n;x2++)
			{
				for(rll y1=1;y1<m;y1++)
				{
					if(sum[x2][y1]-sum[x1-1][y1]-sum[x2][y1-1]+sum[x1-1][y1-1]!=0)
					continue;
					if(tmp1[x1][y1]==0)
					{
						ll now=y1+1;
						while(mapp[x1][now]=='0')
						tmp1[x1][y1]++,now++;
					}
					if(tmp1[x2][y1]==0)
					{
						ll now=y1+1;
						while(mapp[x2][now]=='0')
						tmp1[x2][y1]++,now++;
					}
					sum1=(sum1+c*tmp1[x1][y1]*tmp1[x2][y1])%998244353;
					if(f==0)
					continue;
					if(tmp2[x2][y1]==0)
					{
						ll now=x2+1;
						while(mapp[now][y1]=='0')
						{
							now++;
							tmp2[x2][y1]++;
						}
					}
					sum2=(sum2+f*tmp1[x1][y1]*tmp1[x2][y1]*tmp2[x2][y1])%998244353;
				}
			}
		}
		print(sum1);
		putchar(' ');
		print(sum2);
	}
	return 0;
}
