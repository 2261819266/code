#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int m,n,a[1001][1001],b[1001][1001][2],c,f,t,d,p=0,q=0;
string ss;
inline int rd()
{
	int l=1,r=0;
	char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-')l=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		r=r*10+s-'0';
		s=getchar();
	}
	return l*r;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=rd();
	d=rd();
	while(t--)
	{
		n=rd();
		m=rd();
		c=rd();
		f=rd();
		p=0;
		q=0;
		memset(a,0x3f3f,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>ss;
			for(int j=0;j<m;j++)
			{
				a[i][j+1]=ss[j]-'0';
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1){b[i][j][0]=-1;b[i][j][1]=-1;continue;}
			for(int o=i+1;o<=n+1;o++)
			{
				if(a[o][j]!=0)
				{
					b[i][j][0]=o-i-1;
					break;
				}
			}
			for(int o=j+1;o<=m+1;o++)
			{
				if(a[i][o]!=0)
				{
					b[i][j][1]=o-j-1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1||a[i+1][j]==1||a[i+2][j]==1||a[i][j+1]==1)continue;
			if(b[i][j][1]<=0)continue;
			for(int o=i+2;o<=n;o++)
			{
				if(a[o][j]==0)
				{
					p+=max(0,b[o][j][1])*max(0,b[i][j][1]);
					p%=998244353;
					q+=max(0,b[i][j][1])*max(0,b[o][j][1])*max(0,b[o][j][0]);
					q%=998244353;
				}
				else break;
			}
		}
		printf("%d %d",p*c,q*f);
	}
	return 0;
}
