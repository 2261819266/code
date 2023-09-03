#include<bits/stdc++.h>
#define int long long
#define LL unsigned long long
using namespace std;
int t,n,a[100005],b[100005],maxx1[3005][1005],l,r,ans,lg[100005],maxx2[3005][1005],q,sum1=0,sum2=0;
LL Mod=pow(2,64);
int Max(int u,int v)
{
	if(u<=v) u=v;
	return u;
}
void solve(int x)
{
	lg[1]=0;
	for(int i=2;i<=x;i++)
	{
		lg[i]=lg[i]+1;
	}
}
void f1()
{
	for(int j=1;j<=lg[n];j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			maxx1[i][j]=Max(maxx1[i][j-1],maxx1[i+(1<<(j-1))][j-1]);
		}
	}
}
void f2()
{
		for(int j=1;j<=lg[n];j++)
	{
		for(int i=1;i<=n-(1<<(j))+1;i++)
		{
			maxx2[i][j]=Max(maxx2[i][j-1],maxx2[i+(1<<(j-1))][j-1]);
		}
	}
}
int query1(int x,int y)
{
	int k=log2(y-x+1);
	int res=0;
	res=Max(maxx1[x][k],maxx1[y-(1<<k)+1][k]);
	return res;
}
int query2(int x,int y)
{
	int k=log2(y-x+1);
	int res=0;
	res=Max(maxx2[x][k],maxx2[y-(1<<k)+1][k]);
	return res;
}
signed main()
{
   freopen("match.in","r",stdin);
   freopen("match.out","w",stdout);
   cin>>t>>n;
   //solve(n);
   for(int i=1;i<=n;i++)
   {
   	cin>>a[i];
   }
   for(int i=1;i<=n;i++)
   {
   	cin>>b[i];
   }
  // for(int i=1;i<=n;i++)
  // {
  // 	 maxx1[i][0]=a[i];
   //	 maxx2[i][0]=b[i];
   //}
   cin>>q;
   for(int i=1;i<=q;i++)
   {
     	cin>>l>>r;
     	ans=0;
   	for(int j=l;j<=r;j++)
  	{
   		for(int k=j;k<=r;k++)
   		{
   			sum1=0,sum2=0;
   			  for(int x=j;x<=k;x++)
   			  {
   			  	  sum1=Max(sum1,a[x]);
   			  	  sum2=Max(sum2,b[x]);
				 }
			  ans+=sum1*sum2;
		   }
		   ans=ans%Mod;
	   }
	   cout<<ans<<endl;
   }
   
   return 0;
}


