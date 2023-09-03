#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005,p=998244353;
int n,m,ans1,ans2;
int b[N][N],c[N][N];
char a[N][N];

int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}
void work()
{
	ans1=ans2=0;
	n=read();m=read();read();read();
	for(int i=1;i<=n;i++)cin>>a[i]+1;
	for(int i=1;i<=n;i++)
	for(int j=m;j>=1;j--)
	if(a[i][j]=='1')b[i][j]=0;
	else b[i][j]=b[i][j+1]+1;
	for(int i=n;i>=1;i--)
	for(int j=1;j<=m;j++)
	if(a[i][j]=='1')c[i][j]=0;
	else c[i][j]=c[i+1][j]+1;
	
	for(int j=1;j<=m;j++)
	{
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='1'){s=0;continue;}
			int s1=s;
			if(a[i-1][j]=='0')s1-=(b[i-1][j]-1);
			ans1+=s1*(b[i][j]-1);
			ans2+=s1*(b[i][j]-1)*(c[i][j]-1);
			s+=(b[i][j]-1);
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read();read();
	while(T--)work();
}
