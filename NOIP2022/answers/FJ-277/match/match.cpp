#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
long long read()
{
	long long res=0,f=0;char c;
	while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')f=1;else res=c-'0';
	while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';
	return f?-res:res;
}
const int N=2.5e5+10;
int T,n,Q,l,r,a[N],b[N],f[2][20][N],ans,m1,m2;
int m(bool fl,int l,int r)
{
	int x=r-l+1,len=0;
	while(x>0)len++,x>>=1;
	return max(f[fl][len-1][l],f[fl][len-1][r-(1<<(len-1))+1]);
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read();n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int j=1;j<=n;j++)b[j]=read();
	for(int i=1;i<=n;i++)f[0][0][i]=a[i];
	for(int p=1,nw=1;nw+nw<=n;p++,nw<<=1)
		for(int i=1;i+nw+nw-1<=n;i++)
			f[0][p][i]=max(f[0][p-1][i],f[0][p-1][i+nw]);
	for(int i=1;i<=n;i++)f[1][0][i]=b[i];
	for(int p=1,nw=1;nw+nw<=n;p++,nw<<=1)
		for(int i=1;i+nw+nw-1<=n;i++)
			f[1][p][i]=max(f[1][p-1][i],f[1][p-1][i+nw]);
	Q=read();
	while(Q--)
	{
		l=read();r=read();ans=0;
		for(int i=l;i<=r;i++)
		{
			for(int j=i;j<=r;j++)
			{
				m1=m(0,i,j);m2=m(1,i,j);
//				printf("%d %d %d %d\n",i,j,m1,m2);
				ans+=m1*m2;
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
