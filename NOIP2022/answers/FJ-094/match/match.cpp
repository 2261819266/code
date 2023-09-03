#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	char cc=getchar();
	long long ss=0;
	while((cc<'0'||cc>'9')&&cc!='-')cc=getchar();
	while(cc>='0'&&cc<='9')ss=(ss<<1)+(ss<<3)+(cc^48),cc=getchar();
	return ss;
}
long long T,n,Q,L,R,a[3011],b[3011],am[3011][3011],bm[3011][3011];
unsigned long long ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read();n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		am[i][i]=a[i];
		for(int j=i+1;j<=n;j++)am[i][j]=max(am[i][j-1],a[j]);
	}
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)
	{
		bm[i][i]=b[i];
		for(int j=i+1;j<=n;j++)bm[i][j]=max(bm[i][j-1],b[j]);
	}
	Q=read();
	for(int ii=1;ii<=Q;ii++)
	{
		ans=0;
		L=read();R=read();
		for(int i=L;i<=R;i++)
		{
			for(int j=i;j<=R;j++)
			{
				ans+=am[i][j]*bm[i][j];
			}
		}
		cout<<ans<<endl;
	}
}
