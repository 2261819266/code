#include<bits/stdc++.h>
#define mod 998244353
#define int long long
#define N 1010
using namespace std;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int T,id,n,m,c,f,q[N][N],p[N][N],a[N][N],ct[N][N],cf[N][N],ansc,ansf;
char ch;
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)
	{
		memset(q,0,sizeof(q)); memset(p,0,sizeof(p));
		memset(ct,0,sizeof(ct)); memset(cf,0,sizeof(cf)); ansc=0; ansf=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>ch;
				if(ch=='0') a[i][j]=1;
				else a[i][j]=0;
			}
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--)
				if(a[i][j]==0) continue;
				else q[i][j]=(q[i][j+1]+1)%mod;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]==0) continue;
				else p[i][j]=(p[i-1][j]+q[i][j]-1+mod)%mod;
		
		for(int i=3;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0||a[i-1][j]==0) continue;
				ct[i][j]=p[i-2][j]*(q[i][j]-1+mod)%mod;
				ansc=(ansc+ct[i][j])%mod;
			}
		for(int i=4;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0||a[i-1][j]==0) continue;
				cf[i][j]=ct[i-1][j]+cf[i-1][j];
				ansf=(ansf+cf[i][j])%mod;
			}
		}
		cout<<c*ansc%mod<<" "<<f*ansf%mod<<endl;
	}
}
