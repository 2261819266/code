#include<bits/stdc++.h>
using namespace std;
long long t,n,m,id,c,f;
int a[1001][1001];
long long sx[1001][1001],sy[1001][1001];
long long ans,mod=998244353;
long long nxtx[1001][1001],nxty[1001][1001];
void pre()
{
	for(int i=1;i<=n;i++)
	{
	int j=1,jf=1;
		while(jf<=m)
		{	
	    	while(sx[i][j]==sx[i][jf]&&j<=m)++j;
			--j;
	    	for(int k=jf;k<=j;k++)nxty[i][k]=j;
	    	jf=j+2;	
		    j=jf;
		    //cout<<j<<endl;
		}
	}
}
void sc()
{
	ans=0;
	for(int y0=1;y0<=m-1;y0++)
	{
		for(int x1=1;x1<=n-2;x1++)
		{
			//cout<<x1<<y0<<endl;
			if(a[x1][y0])continue;
			int x2=x1+2;
			int y1=nxty[x1][y0];
			if(y1==y0)continue;
			while(sy[x2][y0]==sy[x1][y0]&&x2<=n)
			{
				//cout<<x2<<endl;
				int y2=nxty[x2][y0];//cout<<x1<<' '<<x2<<' '<<y0<<' '<<y1<<' '<<y2<<endl;
				ans=(ans+(y1-y0)*(y2-y0))%mod;
				++x2;
			}
		}
	}
	cout<<(ans*c)%mod<<' ';
}
void sf()
{
	ans=0;
	for(int y0=1;y0<=m-1;y0++)
	{
		for(int x1=1;x1<=n-2;x1++)
		{
			if(a[x1][y0])continue;
			int x2=x1+2;
			int y1=nxty[x1][y0];
			if(y1==y0)continue;
			while(sy[x2][y0]==sy[x1][y0]&&x2<=n)
			{
				//cout<<x2<<endl;
			int y2=nxty[x2][y0];
				int x3=x2+1;
				while(sy[x3][y0]==sy[x1][y0]&&x3<=n)++x3;
				--x3;
				//cout<<y1<<' '<<y2<<endl;
				
				ans=(ans+(y1-y0)*(y2-y0)*(x3-x2))%mod;
				++x2;
			}
		}
	}
	cout<<(ans*f)%mod<<'\n';
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	char w[100001];
	
	while(t--)
	{
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		{
			cin>>w;
			for(int j=1;j<=m;j++)
			a[i][j]=w[j-1]-48;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sx[i][j]=sx[i][j-1]+a[i][j];
				//cout<<a[i][j]<<' ';
			}
			//cout<<endl;
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				sy[i][j]=sy[i-1][j]+a[i][j];
			}
		}pre();
		sc();
		sf();
	}
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
