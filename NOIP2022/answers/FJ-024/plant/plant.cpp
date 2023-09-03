#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x;
}
const int mod=998244353;
const int maxN=1010;
char s[maxN];
int a[maxN][maxN];
int n,m,c,f;
int b[maxN][maxN];
int ans_c,ans_f;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--)
	{
		n=read();
		m=read();
		c=read();
		f=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				a[i][j]=(s[j]-'0')^1;
		}
		for(int i=1;i<=n;i++)
		{
			b[i][m+1]=0;
			for(int j=m;j>=1;j--)
				b[i][j]=(a[i][j]==0?0:b[i][j+1]+1);
		}
		ans_c=0;
		ans_f=0;
		for(int i=1;i<=m;i++)
		{
			int xz[2]={};
			for(int j=n,x=0;j>=1;j--)
			{
				if(a[j][i]) x++;
				else
				{
					x=0;
					xz[0]=0;
					xz[1]=0;
					continue;
				}
				xz[0]=(xz[0]+b[j][i]-1)%mod;
				if(j-2>=1&&a[j-1][i]&&a[j-2][i]) ans_c=(ans_c+(long long)(b[j-2][i]-1)*xz[0])%mod;
				xz[1]=(long long)(xz[1]+(x-1)*(b[j][i]-1))%mod;
				if(j-2>=1&&a[j-1][i]&&a[j-2][i]) ans_f=(ans_f+(long long)(b[j-2][i]-1)*xz[1])%mod;
			}
		}
		if(ans_c<0) ans_c+=mod;
		if(ans_f<0) ans_f+=mod;
		printf("%d %d\n",c*ans_c,f*ans_f);
	}
	return 0;
}
