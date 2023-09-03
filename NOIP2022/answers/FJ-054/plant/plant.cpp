#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=1e3+10,MOD=998244353;
int a[N][N];
int suf[N][N];
int color[N];
int n,m,c,f;
void get_suf()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(a[i][j])
				continue;
			else
				suf[i][j]=suf[i][j+1]+1;
		}
	}
	return ;
}
int tot=0;
int tmod(int x)
{
	return (x%MOD+MOD)%MOD;
}
int get_c(int row,int col)
{
	tot++;
	for(int i=row;i<=n;i++)
	{
		if(!a[i][col])
			color[i]=tot;
		else
			break;
	}
	int sum=0;
	int ans=0;
	for(int i=row+2;i<=n&&color[i]==color[row];i++)
	{
		sum=tmod(((LL)sum+suf[i-2][col]-1)%MOD);
		ans=tmod(((LL)ans+(LL)(suf[i][col]-1)*sum)%MOD);
	}
	return ans;
}
int get_f(int row,int col)
{
	int p=0;
	tot++;
	for(int i=row;i<=n;i++)
	{
		if(!a[i][col])
		{
			color[i]=tot;
			p=i;	
		}
		else
			break;
	}
	int sum=0;
	int ans=0;
	for(int i=p-3;i>=row;i--)
	{
		sum=tmod(((LL)sum+(LL)(suf[i+2][col]-1)*(p-i-2)%MOD)%MOD);
		ans=tmod(((LL)ans+(LL)(suf[i][col]-1)*sum%MOD)%MOD);
	}
	return ans;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(suf,0,sizeof(suf));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c;
				a[i][j]=c-'0';
			}	
		}
		get_suf();
		int ans_c=0,ans_f=0;
		for(int j=1;j<=m;j++)
		{
			memset(color,0,sizeof(color));
			tot=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]||color[i])
					continue;
				else
				{
					ans_c=((LL)ans_c+get_c(i,j))%MOD;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			memset(color,0,sizeof(color));
			tot=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]||color[i])
					continue;
				else
				{
					ans_f=((LL)ans_f+get_f(i,j))%MOD;
				}
			}
		}
		ans_c*=c;
		ans_f*=f;
		printf("%d %d\n",ans_c,ans_f);
	}
	return 0;
	
}
