#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
inline int read()
{
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		g*=10;
		g+=ch-'0';
		ch=getchar();
	}
	return f*g;
}
int n,m,c,f;
//int a[1005][1005];
int sh[1005][1005];
int sl[1005][1005];
ll th[1005][1005];
int tl[1005][1005];
char ch[1005][1005];

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t=read(),id=read();
	while(t--)
	{
		memset(sh,0,sizeof(sh));
		memset(sl,0,sizeof(sl));
		memset(th,0,sizeof(th));
		memset(tl,0,sizeof(tl));
	//	memset(ffg,0,sizeof(ffg));
	//	memset(sfg,0,sizeof(sfg));
		if(id==1)
		{
			printf("0\n");
		}
		n=read(),m=read(),c=read(),f=read();	
		for(int i=1;i<=n;i++)
		{
			cin>>ch[i]+1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sh[i][j]=sh[i][j-1]+(int)ch[i][j]-'0';
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				sl[j][i]=sl[j][i-1]+(int)ch[i][j]-'0';
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ch[i][j]=='1')continue;
				int p=upper_bound(sh[i]+1,sh[i]+1+m,sh[i][j])-sh[i];
				if(p==m&&sh[i][m]==sh[i][m-1])
				{
					p=m+1;
				}
				while(j<p)
				{
					th[i][j]=p-j-1;
					j++;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(ch[i][j]=='1')continue;
				int p=upper_bound(sl[j]+1,sl[j]+1+n,sl[j][i])-sl[j];
				if(p==n&&sl[j][n]==sl[j][n-1])
				{
					p=n+1;
				}
				while(i<p)
				{
					tl[i][j]=p-i-1;
					i++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sh[i][j]=sh[i][j-1]+th[i][j];
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				sl[i][j]=sl[i-1][j]+th[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				th[i][j]=1ll*(sh[i][j]-sh[i][j-1])*(tl[i][j])%mod;
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				th[i][j]+=th[i-1][j];
				th[i][j]%=mod;
			}
		}
		ll ansc=0,ansf=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ch[i][j]=='1')continue;
				if(tl[i][j]>1)
				{
					ansc+=1ll*(sh[i][j]-sh[i][j-1])*(sl[i+tl[i][j]][j]-sl[i+1][j])%mod;
					ansc%=mod;
					ansf+=1ll*(sh[i][j]-sh[i][j-1])*(th[i+tl[i][j]-1][j]-th[i+1][j])%mod;
					ansf%=mod;
				}
			//	cout<<i<<' '<<j<<' '<<ansc<<' '<<ansf<<endl;
			}	
		}
		ll cc=c,ff=f;
		ansc*=cc;
		ansf*=ff;
		printf("%lld %lld\n",ansc,ansf);		
	}
	return 0;
}
//	for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%d ",tl[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%d ",sh[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%d ",sl[i][j]);
//			}
//			printf("\n");
//		}1000000
