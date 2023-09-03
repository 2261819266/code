#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int read()
{
	char ch;
	int s=1;
	while((ch=getchar())<'0' || ch>'9')
	  if(ch=='-')
	    s=-1;
	int res=ch-'0';
	while((ch=getchar())>='0' && ch<='9')
	  res=(res<<3)+(res<<1)+ch-'0';
	return res*s;
}
int T,ID;
int n,m;
ll C,F;
int a[1111][1111];
int you[1111][1111];
int xia[1111][1111];
ll s1[1111][1111];
ll s2[1111][1111];
ll ans1,ans2;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),ID=read();
	while(T--)
	{
		n=read(),m=read(),C=read(),F=read();
		for(int i=0;i<=n+1;i++)
		  for(int j=0;j<=m+1;j++)
		    s1[i][j]=s2[i][j]=you[i][j]=xia[i][j]=a[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char ch;
				while((ch=getchar())<'0' || ch>'1');
				a[i][j]=ch-'0';
			} 
		}
		for(int i=1;i<=n;i++)
		{
			int now=0;
			for(int j=m;j>=1;j--)
			{
				you[i][j]=now;
				if(a[i][j]==1)
				  now=0;
				else
				  now++;
			}
		}
		for(int j=1;j<=m;j++)
		{
			int now=0;
			for(int i=n;i>=1;i--)
			{
				xia[i][j]=now;
				if(a[i][j]==1)
				  now=0;
				else
				  now++;
			}
		}
		for(int j=1;j<=m;j++)
		  for(int i=1;i<=n;i++)
			s1[i][j]=(s1[i-1][j]+you[i][j])%mod;
		for(int j=1;j<=m;j++)
		  for(int i=1;i<=n;i++)
			s2[i][j]=(s2[i-1][j]+s1[i][j])%mod;
		ans1=0,ans2=0;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
			if(a[i][j]==0 && xia[i][j]>=2)
			{
				ll aa=(s1[i+xia[i][j]][j]-s1[i+1][j]+mod)%mod;
				ans1=(ans1+aa*(ll)you[i][j])%mod;
			}
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
			if(a[i][j]==0 && xia[i][j]>=3)
			{
				ll aa=(s2[i+xia[i][j]-1][j]-s2[i+1][j]+mod)%mod;
				aa=(aa-s1[i+1][j]*(xia[i][j]-2LL)%mod+mod)%mod;
				ans2=(ans2+aa*(ll)you[i][j])%mod;
			}
		printf("%lld %lld\n",ans1*C,ans2*F);
	}
}
/*
3 0
4 3 1 1
001
010
000
000

6 6 1 1
000010
011000
000110
010000
011000
000000

16 12 1 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111
*/

