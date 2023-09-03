#include<bits/stdc++.h>
using namespace std;
int t,id,d[1001][1001],n,m,c,f,sumx[1001][1001]={},sumy[1001][1001]={};
long long ansc=0,ansf=0;
char cs[1001];
int mod=998244353;
inline void yu()
{
	for(register int i=1;i<=m;i++)
	for(register int j=1;j<=n;++j)
	{sumx[j][i]=sumx[j-1][i]+d[j][i];
	}
	for(register int i=1;i<=n;i++)
	for(register int j=1;j<=m;++j)
	{sumy[i][j]=sumy[i][j-1]+d[i][j];
	}
}
inline int fi(int a,int b)
{
	for(register int i=m;i>b;i--)
	if(sumy[a][i]-sumy[a][b-1]==i-b+1)
	return i;
	return b;
}
inline void ch()
{   for(register int x1=1;x1<n-1;++x1)
	for(register int x2=x1+2;x2<=n;++x2)
	for(register int y0=1;y0<m;++y0)
	{
	if(sumx[x2][y0]-sumx[x1-1][y0]==x2-x1+1){int y1=fi(x1,y0);
		int y2=fi(x2,y0);ansc=(ansc+(y1-y0)*(y2-y0))%mod;	
	}
	}
	}
inline void fh()
{
	for(register int x1=1;x1<n-2;++x1)
	for(register int x3=x1+3;x3<=n;++x3)
	for(register int x2=x1+2;x2<x3;++x2)
	for(register int y0=1;y0<m;++y0)
	{
	if(sumx[x3][y0]-sumx[x1-1][y0]==x3-x1+1){int y1=fi(x1,y0);
		int y2=fi(x2,y0);ansf=(ansf+(y1-y0)*(y2-y0))%mod;	
	}
 }} 

int main()
{
	freopen("plant.in","r",stdin);
freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(register int j=1;j<=t;++j)
	{
		cin>>n>>m>>c>>f;
		for(register int i=1;i<=n;++i)
		{cin>>cs;
		for(register int z=0;z<m;++z)
		if(cs[z]=='1'){d[i][z+1]=0;
		}
		else d[i][z+1]=1; 
		}
		yu();
		ch();
		fh();
		printf("%lld %lld\n",(c*ansc)%mod,(f*ansf)%mod);
		memset(sumx,0,sizeof(sumx));
		memset(sumy,0,sizeof(sumy));
		ansc=ansf=0;
	}
	return 0;
 } 
