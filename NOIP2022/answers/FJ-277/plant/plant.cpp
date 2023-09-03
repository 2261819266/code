#include<bits/stdc++.h>
#define int long long
#define reg register
using namespace std;
long long read()
{
	long long res=0,f=0;char ch;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-');
	if(ch=='-')f=1;else res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-'0';
	return f?-res:res;
}
const int mod=998244353,N=1010;
int s[N][N],a[N][N],n,m,T,c,f,ans,sum,id,ls,p[N][N];
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();id=read();
	while(T--)
	{
		n=read();m=read();c=read();f=read();ans=0;
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++,getchar())
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=getchar()-'0';
			}
		}
		for(int i=1;i<=n;i++)
		{
			sum=0;
			for(int j=m;j;j--)
			{
				if(a[i][j]==1)sum=0;
				else sum++;
				s[i][j]=sum;
			}
		}
//		for(int i=1;i<=n;i++,puts(""))
//		{
//			for(int j=1;j<=m;j++)printf("%d ",s[i][j]);
//		}
		for(int i=1;i<=m;i++)
		{
			sum=0,ls=0;
			for(int j=1;j<=n;j++)
			{
//				printf("%d ",sum);
				if(a[j][i]==1){sum=0,ls=j;continue;}
				else if(j>2)sum=(sum+(ls<j-1)*max(0ll,s[j-2][i]-1))%mod;
				ans=(ans+sum*(s[j][i]-1))%mod;
			}
		}
		ans=c*ans%mod;
		printf("%lld ",ans);
		ans=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j;j--)
			{
				if(a[j][i]==1){sum=0;continue;}
				if(a[j][i]==0)
				{
					if(a[j+1][i]==1||j==n)p[j][i]=j;
					else p[j][i]=p[j+1][i];
				}
			}
		}
//		for(int i=1;i<=n;i++,puts(""))
//		{for(int j=1;j<=m;j++)printf("%d ",p[i][j]);
//		}
		for(int i=1;i<=m;i++)
		{
			sum=0,ls=0;
			for(int j=1;j<=n;j++)
			{
//				printf("%d ",sum);
				if(a[j][i]==1){sum=0,ls=j;continue;}
				else if(j>2)sum=(sum+(ls<j-1)*max(0ll,s[j-2][i]-1))%mod;
				ans=(ans+sum*(s[j][i]-1)*max(0ll,p[j][i]-j))%mod;
			}
		}
		ans=f*ans%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 0
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
4 2 1 1
00
01
00
01
*/
