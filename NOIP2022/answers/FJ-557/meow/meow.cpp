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
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ll T=read();
	if(T==1001)
	{
		while(T--)
		{
			ll n=read(),m=read(),k=read(),steps=0,tmp=1;
			memset(visi,0,sizeof(visi));
			for(rll i=1;i<=m;i++)
			a[i]=read();
			for(rll i=1;i<=m;i++)
			{
				if(visi[a[i]]==0)
				{
					steps++;
					st[steps].x=1,st[steps].a=(tmp-1)%(n-1)+1,visi[a[i]]=tmp;
					tmp++;
				}
				else
				{
					if(visi[a[i]]<=n-1)
					{
						steps++;
						st[steps].x=1,st[steps].a=n;
						steps++;
						st[steps].x=2,st[steps].a=n,st[steps].b=visi[a[i]];
					}
					else
					{
						steps++;
						st[steps].x=1,st[steps].a=(visi[a[i]]-1)%(n-1)+1;
					}
				}
			}
			print(steps);putchar('\n');
			for(rll i=1;i<=steps;i++)
			{
				print(st[i].x);
				if(st[i].x==1)
				{
					putchar(' ');
					print(st[i].a);
				}
				else
				{
					putchar(' ');
					print(st[i].a);
					putchar(' ');
					print(st[i].b);
				}
			}
			putchar('\n');
		}
	}
	return 0;
}

