#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const long long p=9998244353;
int T,id,n,m,c,f,a[1005][1005],l[1005][1005],h[1005][1005],k;
char s;
long long ans1,ans2,ans3,ans;
int main()
{
	freopen("plant","r",stdin);
	freopen("plant","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		memset(l,0,sizeof(l));
		memset(h,0,sizeof(h));
		memset(a,0,sizeof(a));
		ans=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>s;
				a[i][j]=(int)(s-'0');
			}
		}
		if(c==0&&f==0)
		{
			printf("0 0\n");
			continue ;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=1;j--)
			{
				if(a[i][j]==1)h[i][j]=0;
				else h[i][j]=h[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=n;i>=1;i--)
			{
				if(a[i][j]==1)l[i][j]=0;
				else l[i][j]=l[i+1][j]+1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]==1)continue ;
				k=i;
				ans1=0;
				ans2=0;
				ans3=0;
				for(k=i;k<=i+l[i][j]-1;k++)
				{
					ans1+=(h[k][j]-1);
					ans2+=(h[k][j]-1)*(h[k][j]-1);
					ans3+=(h[k][j]-1)*max(0,h[k-1][j]-1);
				}
				ans1=ans1*ans1;
				ans1-=ans2;
				ans1/=2;
				ans1-=ans3;
				ans1%=p;
				ans=(ans+ans1)%p;
				i=k;
			}
		}
		printf("%lld ",(ans*c)%p);
		if(f==0)
		{
			printf("0\n");
			continue ;
		}
		ans=0;
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]==1)continue ;
				k=i;
				ans1=0;
				ans2=0;
				ans3=0;
				for(k=i;k<=i+l[i][j]-1;k++)
				{
					ans1+=(h[k][j]-1);
				}
				ans1-=(h[k-1][j]-1);
				for(int x=k-1;x>i;x--)
				{
					ans1-=(h[x-1][j]-1);
					ans2+=(l[x][j]-1)*ans1*(h[x][j]-1);
					ans2%=p;
				}
				ans=(ans+ans2)%p;
				i=k;
			}
		}
		printf("%lld\n",(ans*f)%p);
	}
	return 0;
}
