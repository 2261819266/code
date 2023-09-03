#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read()
{
	int f=1,x=0;char c=getchar();
	while(c<'0' or c>'9')
	{if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<'9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}

const int p=1000000007;
int pow2[1000006];

signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n=read(),m=read();
	pow2[0]=1;
	for(int i=1;i<=1000006;i++)
	{
		pow2[i]=pow2[i-1]*2%p;
	}
	if(1==1)
	{
		LL ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans+(pow2[m-i+1]*(n-i+1)%p))%p;
		}
		if(ans==0)
		{
			cout<<p;
		}
		else
		{
			cout<<ans-1;
		}
	}
	else
	{
		
	}
	return 0;
}

