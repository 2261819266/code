#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
#define M 998244353
using namespace std;
int T,id,n,m,C,F,ans1,ans2,a[1001][1001],f[1001][1001],S[1001][1001],up[1001][1001],down[1001][1001];
string str;
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&C,&F);
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			for(int j=1;j<=m;j++)
				a[i][j]=str[j-1]-'0';
		}
		ans1=ans2=0;
		memset(f,0,sizeof(f));
		memset(S,0,sizeof(S));
		memset(up,0,sizeof(up));
		memset(down,0,sizeof(down));
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--)
			{
				if(a[i][j]==1) f[i][j]=0;
				else if(j==n) f[i][j]=1;
				else f[i][j]=f[i][j+1]+1;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==1) up[i][j]=0;
				else if(a[i-1][j]==1) up[i][j]=i;
				else up[i][j]=up[i-1][j];
				if(f[i][j]>1) S[i][j]=(S[i-1][j]+f[i][j]-1+M)%M;
				else S[i][j]=S[i-1][j];
			}
		for(int i=n;i>=1;i--)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==1) down[i][j]=0;
				else if(i==n||a[i+1][j]==1) down[i][j]=i;
				else down[i][j]=down[i+1][j];
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			//	cout<<down[i][j]<<(j==m?'\n':' ');		922107 forever
			{
				if(f[i][j]>1&&a[i][j]==0)
					ans1=(ans1+(f[i][j]-1)*(S[i-2][j]-S[up[i][j]-1][j]+M))%M;
				if(down[i][j]>i&&f[i][j]>1&&a[i][j]==0)
					ans2=(ans2+(down[i][j]-i)*(f[i][j]-1)%M*(S[i-2][j]-S[up[i][j]-1][j]+M))%M;
			}
		printf("%lld %lld\n",C*ans1,F*ans2);
	}
	return 0;
}
