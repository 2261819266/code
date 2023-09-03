#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char cc=getchar();
	int ss=0,ff=1;
	while((cc<'0'||cc>'9')&&cc!='-')cc=getchar();
	if(cc=='-')ff=-1,cc=getchar();
	while(cc>='0'&&cc<='9')ss=(ss<<1)+(ss<<3)+(cc^48),cc=getchar();
	return ss*ff;
}
long long T,id,n,m,mod=998244353,C,F,a[1011][1011],y[1011][1011],x[1011][1011],u,s1,s2,ansc,ansf;//you xia
char aa;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();id=read();
	while(T)
	{
		T--;
		cin>>n>>m>>C>>F;
		ansc=0;ansf=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=0,y[i][j]=0,x[i][j]=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		{
			cin>>aa;
			if(aa=='1')
			{
				a[i][j]=1;
				y[i][j]=-1;
				x[i][j]=-1;
				for(int k=j-1;k>=1;k--)
				{
					if(a[i][k])break;
					y[i][k]=y[i][k+1]+1;
				}
				for(int k=i-1;k>=1;k--)
				{
					if(a[k][j])break;
					x[k][j]=x[k+1][j]+1;
				} 
			}
			else a[i][j]=0;	
			if(aa=='0'&&j==m)
			{
				y[i][j]=0;
				for(int k=j-1;k>=1;k--)
				{
					if(a[i][k])break;
					y[i][k]=y[i][k+1]+1;
				}
			}
			if(aa=='0'&&i==n)
			{
				x[i][j]=0;
				for(int k=i-1;k>=1;k--)
				{
					if(a[k][j])break;
					x[k][j]=x[k+1][j]+1;
				} 
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][j])continue;
				u=i;
				s1=y[u][j];
				while(!a[u+1][j]&&u<n)
				{
					u++;
					ansc+=y[u][j]*(s1-y[u-1][j]);
					ansf+=x[u][j]*y[u][j]*(s1-y[u-1][j]);
					s1+=y[u][j];
				}
				i=u+1;
				s1=0;
				ansc=ansc%mod;
				ansf=ansf%mod;
			}
		}
		ansc=ansc*C%mod;
		ansf=ansf*F%mod;
		cout<<ansc<<" "<<ansf<<endl;
	}
}
