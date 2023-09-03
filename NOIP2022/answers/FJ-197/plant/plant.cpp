#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m;
bool a[1050][1050];
ll rig[1050][1050],dow[1050][1050],rr[1050][1050],dd[1050][1050];
inline ll Read()
{
	ll x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') { x=x*10+ch-48;ch=getchar(); }
	return x;
}
inline int Read1()
{
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') { x=x*10+ch-48;ch=getchar(); }
	return x;
}
inline int Read2()
{
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	return ch-48;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
    int T,id;
    ll c,f;
    T=Read1(),id=Read1();
    while(T--)
    {
    	n=Read1(),m=Read1(),c=Read(),f=Read();
    	for(int i=1;i<=n;i++)
    	{
    	  for(int j=1;j<=m;j++)
    	  {
    	    a[i][j]=Read2();
			rr[i][j]=dd[i][j]=rig[i][j]=dow[i][j]=0;
    	  }
    	  a[i][m+1]=1;
    	  rig[i][m+1]=0;
		}
		for(int i=1;i<=m;i++) rr[n+1][i]=dd[n+1][i]=dow[n+1][i]=0;
		for(int i=1;i<=n;i++)
		  for(int j=m;j>=1;j--)
		  {
		  	if(a[i][j]) rr[i][j]=rig[i][j]=0;
		  	else rig[i][j]=rig[i][j+1]+1;
		  }
		for(int j=1;j<=m;j++)
		  for(int i=n;i>=1;i--)
		  {
		  	if(a[i][j]) dow[i][j]=0,dd[i][j]=0;
		  	else 
			{
			  dow[i][j]=dow[i+1][j]+1;
			  if(rig[i][j]>=1) 
			  {
			  dd[i][j]=(dd[i][j+1]+(rig[i][j]-1)*(dow[i][j]-1)%MOD)%MOD;
		      rr[i][j]=rr[i+1][j]+rig[i][j]-1;
			  }
		    }
		  }
		ll ansc=0,ansf=0;
		for(int i=1;i<=n;i++)
		{
		  for(int j=1;j<=m;j++)
		  if(!a[i][j])
		  {
		  	if(rig[i][j]>=2&&dow[i][j]>=3)
			{
			ansc=(ansc+(rig[i][j]-1)*(rr[i+2][j])%MOD)%MOD;
			ansf=(ansf+(rig[i][j]-1)*dd[i+2][j]%MOD)%MOD;
		    }
		  }
	    }
		printf("%lld %lld\n",ansc,ansf);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
