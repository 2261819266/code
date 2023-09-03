#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long mod=998244353;
const long long maxn=1500;
long long n,m,t,id,c,f,fc[maxn][maxn],s[maxn][maxn],ans,cnt,hc[maxn][maxn],ss[maxn][maxn];
long long x,y,ansc,ansf,mid,l,r,a[maxn][maxn],ll,rr,uu,u,anss,ff[maxn][maxn],hf[maxn][maxn];
char cc;
inline long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
void pre()
{
	for(long long i=1;i<=n;i++)
	  for(long long j=1;j<=m;j++)
	  {
	  	fc[i][j]=0;
	  	ff[i][j]=0;
	  	l=j;r=m;u=j;
	  	ll=i;rr=n;uu=i;
		anss=0;anss=0;
	  	while(l<=r)
	  	{
	  		mid=(l+r)>>1;
			if(s[i][mid]-s[i][u-1]==0)ans=mid-u,l=mid+1;
			else r=mid-1; 
		}
	  	while(ll<=rr)
	  	{
	  		mid=(ll+rr)>>1;
			if(ss[mid][j]-ss[uu-1][j]==0)anss=mid-uu,ll=mid+1;
			else rr=mid-1; 
		}		
		if(ans>0)fc[i][j]=ans,hc[i][j]=fc[i][j];
		if(anss>0)ff[i][j]=anss,hf[i][j]=fc[i][j]*ff[i][j]%mod;
	   }
	for(long long i=n;i>=1;i--)
	  for(long long j=1;j<=m;j++)
	  {
	    if(a[i-1][j]!=1)hc[i-1][j]+=hc[i][j],hf[i-1][j]+=hf[i][j],hc[i-1][j]%=mod,hf[i-1][j]%=mod;
	    else hc[i-1][j]=0,hf[i-1][j]=0;	  	
	  }

}
void solve_c()
{
	for(long long i=1;i<=n;i++)
	  for(long long j=1;j<=m;j++)
	  {
	  	if(a[i+1][j]!=1)ansc+=fc[i][j]*hc[i+2][j];ansc%=mod;
	  }
	return;
}
void solve_f()
{
	for(long long i=1;i<=n;i++)
	  for(long long j=1;j<=m;j++)
	  {
	  	if(a[i+1][j]!=1)ansf+=fc[i][j]*hf[i+2][j];ansf%=mod;
	  }
	return;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();id=read();
	while(t--)
	{
		n=read();m=read();c=read();f=read();
		ansc=0,ansf=0;
		memset(a,0,sizeof(a));
		memset(hf,0,sizeof(hf));
		memset(hc,0,sizeof(hc));
		for(long long i=1;i<=n;i++)
		  for(long long j=1;j<=m;j++)
		  {
		  	fc[i][j]=0;
		  	cin>>cc;
		  	a[i][j]=cc-'0';
			s[i][j]=s[i][j-1]+cc-'0';
			ss[i][j]=ss[i-1][j]+cc-'0';
		  }
		pre();
		if(c)solve_c();
		if(f)solve_f();
		printf("%lld %lld\n",ansc,ansf);
	}
	return 0;
}
