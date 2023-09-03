#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
#define ll long long
const int mod=998244353,N=1e3+10;
char s[N][N];
int f[N][N],g[N][N],p[N][N];
void solve()
{
	int ans1=0,ans2=0,n=read(),m=read(),C=read(),F=read();
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=g[i][j]=p[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=m-1;j;j--)
			if(s[i][j]!='1'&&s[i][j+1]!='1')
				f[i][j]=f[i][j+1]+1;
	for(int i=n-1;i;i--)
		for(int j=1;j<=m;j++)
			if(s[i][j]!='1'&&s[i+1][j]!='1')
				p[i][j]=p[i+1][j]+1;	
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			if(s[i][j]=='0')
				g[i][j]=(g[i-1][j]+f[i][j])%mod;		
	for(int i=3;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='1'||s[i-1][j]=='1')continue;
			ans1=((ll)f[i][j]*g[i-2][j]+ans1)%mod;
			ans2=((ll)f[i][j]*g[i-2][j]%mod*p[i][j]%mod+ans2)%mod;
		}
	ans1=(ll)ans1*C%mod;ans2=(ll)ans2*F%mod;
	cout<<ans1<<' '<<ans2<<endl;
	return;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--)solve();
	return 0;
}
