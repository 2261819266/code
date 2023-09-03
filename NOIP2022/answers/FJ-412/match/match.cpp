#include<bits/stdc++.h>
#define N 2500025
#define inf 0x3f3f3f3f
#define mod 998244353
#define ULL unsigned long long
using namespace std;
int read()
{
	char c=getchar();
	int re=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		re=(re<<1)+(re<<3)+(c&15);
		c=getchar();
	}
	return re;
}
int T,n,a[N],b[N],Q,l,r;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read();
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	Q=read();
	while(Q--)
	{
		l=read();
		r=read();
		ULL out=0;
		for(int i=l;i<=r;i++)
		{
			int boa=a[i],bob=b[i];
			for(int j=i;j<=r;j++)
			{
				boa=max(boa,a[j]);
				bob=max(bob,b[j]);
				out+=(ULL)boa*bob;
			}
		}
		printf("%llu\n",out);
	}
}
