#include<iostream>
#include<cstdio>
using namespace std;
const int N=1001; 
const int mod= 998244353;
int n,m,c,f;
int t,id;
int ans1,ans2;
char s[N];
bool mapp[N][N];
int r[N+1][N+1],u[N+1][N+1];
void prt()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<u[i][j]<<" ";
		}
		printf("\n");
	}
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int i,j,k;
	scanf("%d%d",&t,&id);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		ans1=ans2=0;
		for(j=1;j<=n;j++)
			for(k=1;k<=m;k++)
				r[j][k]=u[j][k]=0;
		for(j=1;j<=n;j++)
		{
			scanf("%s",s);
			for(k=0;k<m;k++)
			{
				if(s[k]=='0')
					mapp[j][k+1]=0;
				else
					mapp[j][k+1]=1;
			}
		}
		if(c==0&&f==0)
		{
			printf("0 0\n");
			continue;
		}
		for(j=1;j<=n;j++)
			for(k=m;k>0;k--)
			{
				if(mapp[j][k]==0)
					r[j][k]=r[j][k+1]+1;
				else
					continue;
			}
		for(j=n;j>0;j--)
			for(k=1;k<=m;k++)
			{
				if(mapp[j][k]==0)
					u[j][k]=u[j+1][k]+1;
				else
					continue;
			}
		//枚举C的左
		for(i=1;i<n;i++)
			for(j=1;j<m;j++) 
			{
				if(u[i][j]>2/*纵轴要满足长度限制*/&&r[i][j]>1/*第一条横轴存在*/)
				{
					//枚举下端点并累加答案
					for(k=i+2;k<=i+u[i][j]-1;k++)
					{
						if(r[k][j]>1/*第二条横轴存在*/)
						{
							ans1+=(r[i][j]-1)*(r[k][j]-1);
							ans1%=mod;
						}
					}
				}
			}
		if(f==0)
		{
			printf("%d 0\n",ans1);
			continue;
		}
		//枚举F的左上方点
		for(i=1;i<n;i++)
			for(j=1;j<m-1;j++)
			{
				if(u[i][j]>3/*纵轴要满足长度限制*/&&r[i][j]>1/*第一条横轴存在*/)
				{
					//枚举第二条横轴的位置并累加答案 
					for(k=i+2;k<i+u[i][j]-1;k++)
					{
						if(u[k][j]>1/*这个点不为下端点*/&&r[k][j]>1/*第二条横轴存在*/)
						{
							ans2+=(r[i][j]-1)*(r[k][j]-1)*(u[k][j]-1);
							ans2%=mod;
						}
					}
				}
			}
		printf("%d %d",ans1,ans2);
//		prt();
	}
	return 0;
}
