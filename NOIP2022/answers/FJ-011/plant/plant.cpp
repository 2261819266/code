#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long T,id,n,m,c,f,ans1,ans2,ys[1005][1005],pos[1005][1005];
char a[1005][1005];
long long op;
char ch;
inline void read(long long &x)
{
	op=1,x=0,ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')op=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=op;
}
inline void out(long long x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		out(x/10);
	putchar(x%10+48);
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	read(T),read(id);
	while(T--)
	{
		read(n),read(m),read(c),read(f);
		ans1=0,ans2=0;
		memset(ys,0,sizeof(ys));
		for(long long i=1;i<=n;i++)
		{
			scanf("%s",a[i]+1);
		}
		if(c==0 && f==0)
		{
			printf("0 0\n");
			continue;
		}
		for(long long j=1;j<=n;j++)
		{
			ys[j][m+1]=-1;
		}
		for(long long i=m;i>=1;i--)
		{
			for(long long j=1;j<=n;j++)
			{
				if(a[j][i]=='0')
				{
					ys[j][i]=ys[j][i+1]+1;
				}
				else
				{
					ys[j][i]=-1;
				}
			}
		}
		for(long long i=1;i<=m;i++)
		{
			pos[n+1][i]=-1;
		}
		for(long long j=n;j>=1;j--)
		{
			for(long long i=1;i<=m;i++)
			{
				if(a[j][i]=='0')
				{
					pos[j][i]=pos[j+1][i]+1;
				}
				else
				{
					pos[j][i]=-1;
				}
			}
		}
		for(long long i=1;i<m;i++)
		{
			//check 'C' type
			for(long long j=1;j<n-1;j++)
			{
				if(ys[j][i]==0)
				{
					continue;
				}
				if(a[j][i]=='1' || a[j+1][i]=='1')
				{
					continue;
				}
				for(long long k=j+2;k<=n;k++)
				{
					if(a[k][i]=='1')
					{
						break;
					}
					ans1+=ys[j][i]*ys[k][i];
					ans1%=mod;
				}
			}
			//check 'F' type
			if(f!=0)
			{
				for(long long j=1;j<n-2;j++)
				{
					if(ys[j][i]==0)
					{
						continue;
					}
					if(a[j][i]=='1' || a[j+1][i]=='1' || a[j+2][i]=='1')
					{
						continue;
					}
					for(long long k=j+2;k<j+pos[j][i];k++)
					{
						ans2+=ys[j][i]*ys[k][i]*(j+pos[j][i]-k);
						ans2%=mod;
					}
				}
			}
		}
		ans1=(ans1*c)%mod;
		ans2=(ans2*f)%mod;
		out(ans1),putchar(' '),out(ans2),putchar('\n');
	}
	return 0;
}
