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
long long t,n,a[99999],b[99999],Q,p,q,l,r,sum=0,maxa,maxb;
int main()
{
	ios::sync_with_stdio(false);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();
	n=read();
	for( int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for( int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	Q=read();
	while(Q--)
	{
		sum=0;
		l=read();
		r=read();
		for( int i=r;i>=l;i--)
		{
			for(int j=i;j>=l;j--)
			{
				maxa=0,maxb=0;
				for( int k=i;k>=j;k--)
				{
					maxa=max(maxa,a[k]);
					maxb=max(maxb,b[k]);
				}
				//cout<<maxa<<" "<<maxb<<'\n';
				sum+=maxa*maxb;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
