#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e3+10,mod=998244353;
inline int read()
{
	int n=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=(n<<3)+(n<<1)+(ch-'0');
		ch=getchar();
	}
	return n*f;
}
int a[M][M];
int h[M][M],l[M][M];
ll fc[M][M],ff[M][M];
ll suml[M][M],sumfc[M][M];

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
    int T=read();
	int id=read();
	int c,f;
	while(T--)
	{
		int n=read(),m=read();
		c=read(),f=read();
		string ch;
		for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=m+1;j++)
			   h[i][j]=l[i][j]=fc[i][j]=ff[i][j]=sumfc[i][j]=suml[i][j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>ch;
			for(int j=0;j<m;j++)
				a[i][j+1]=(int)(ch[j]-'0');
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=1;j--)
			{
				if(a[i][j])
				   continue;
				h[i][j]=h[i-1][j]+1;
				l[i][j]=l[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				suml[i][j]=suml[i-1][j];
			    if(l[i][j]>1)
			       suml[i][j]=(suml[i][j]+l[i][j]-1)%mod;
			}
		}
				    
		ll ansc=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sumfc[i][j]=sumfc[i-1][j];
				if(a[i][j]||l[i][j]<=1||h[i][j]<=2)
				   continue;
				   
				ll sum=0;
				
				if(i-2>=1)
				sum=(suml[i-2][j]-suml[i-h[i][j]][j])%mod;
//				cout<<i<<" "<<j<<"  "<<sum<<endl;
				
				fc[i][j]=1ll*sum*(l[i][j]-1)%mod;
				ansc=(ansc+fc[i][j])%mod;
				
				sumfc[i][j]=(sumfc[i][j]+fc[i][j])%mod;
			}
		}
		printf("%lld ",ansc*c%mod);
		ll ansf=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]||h[i][j]<=1)
				   continue;
				ll sum=0;
				
				if(i-1>=1)
				sum=(sumfc[i-1][j]-sumfc[i-h[i][j]][j])%mod;
//				cout<<" "<<i<<" "<<j<<" "<<sum<<endl;
				
				ff[i][j]=sum;
				ansf=(ff[i][j]+ansf)%mod;
			} 
		}
		printf("%lld\n",ansf*f%mod);
	}
}
