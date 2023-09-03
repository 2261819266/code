#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const long long M=998244353;
int t,di,n,m,c,f,a[1001][1001],i,j,ii,h[1001][1001];
long long ans1,ans2;
char e;
void dfs1(int,int);
void dfs2(int,int); 
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&t,&di);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(ii=1;ii<=n;ii++)
		 for(j=1;j<=m;j++)
		 {
		 	e=getchar();
		 	while(e!='0'&&e!='1') e=getchar();
		 	if(e=='1') a[ii][j]=1;
		 }
		if(c==0&&f==0) printf("0 0\n");
		else
		{
			ans1=0;ans2=0;
			if(f==0)
			{
				dfs1(1,3);
				printf("%lld 0\n",(c*(ans1%M))%M);	
			}
			else
			{
				dfs2(1,3);
				printf("%lld %lld\n",(c*(ans1%M))%M,(f*(ans2%M))%M);	
			}
		}
	}
	return 0;
}
void dfs1(int x,int y)
{
	if(x+1>=y) return;
	if(y>n) return;
	if(h[x][y]==1) return;
	h[x][y]=1;
	int iii,z,pd;
	for(z=1;z<m;z++)
	{
		pd=0;
		for(iii=x;iii<=y;iii++)
		{
			if(a[iii][z]==1)
			{
				pd=1;
				break;
			}
		}
		if(pd==1) continue;
		int shu2=0,shu1=0;
		iii=z+1;
		while(a[x][iii]==0&&iii<=m)
		{
			shu1++;
			iii++;
		}
		iii=z+1;
		while(a[y][iii]==0&&iii<=m)
		{
			shu2++;
			iii++;
		}
		ans1=ans1+(shu1*shu2)%M;
		if(ans1>=M) ans1%=M;
	}
	dfs1(x+1,y);
	dfs1(x,y+1);
}
void dfs2(int x,int y)
{
	if(x+1>=y) return;
	if(y>n) return;
	if(h[x][y]==1) return;
	h[x][y]=1;
	int iii,z,pd,t=y-x+5,jjj,k;
	for(z=1;z<m;z++)
	{
		pd=0;
		for(iii=x;iii<=y;iii++)
		{
			if(a[iii][z]==1)
			{
				pd=1;
				break;
			}
		}
		if(pd==1) continue;
		int shu[t],shu1=0;
		for(iii=1;iii<t;iii++) shu[iii]=0;
		iii=z+1;
		while(a[x][iii]==0&&iii<=m)
		{
			shu1++;
			iii++;
		}
		k=0;
		for(jjj=x+2;jjj<=y;jjj++)
		{
			iii=z+1;
			k++;
			while(a[jjj][iii]==0&&iii<=m)
			{
				shu[k]++;
				iii++;
			}
		}
		for(jjj=1;jjj<k;jjj++)
		{
			ans2=ans2+(shu1*shu[jjj])%M;
			if(ans2>=M) ans2%=M;
		}
		
		ans1=ans1+(shu1*shu[k])%M;
		if(ans1>=M) ans1%=M;
	}
	dfs2(x+1,y);
	dfs2(x,y+1);
}
