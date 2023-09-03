#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll read()
{
	char c=getchar(); ll res=0, f=1;
	while(!isdigit(c)) {if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) {res=(res<<3)+(res<<1)+(c^48); c=getchar();}
	return res*f;
}
void write(ll x)
{
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=1005, mod=998244353;
#define right lxx
int n,m,C,F,right[N][N],under[N][N]; char a[N][N];

void cls()
{
	memset(right,0,sizeof right);
	memset(under,0,sizeof under);
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	for(int subtask=1,T=read(),id=read(); subtask<=T; ++subtask,cls())
	{
		n=read(), m=read(), C=read(), F=read();
		for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
		for(int i=1;i<=n;++i)
		{
			for(int j=m;j;--j)
			{
				if(a[i][j]=='1') continue;
				right[i][j] = right[i][j+1] + 1;
			}
		}
		for(int j=1;j<=m;++j)
		{
			for(int i=n;i;--i)
			{
				if(a[i][j]=='1') continue;
				under[i][j] = under[i+1][j] + 1;
			}
		}
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(right[i][j]) --right[i][j];
			if(under[i][j]) --under[i][j];
		}
		ll ansC=0, ansF=0;
		for(int j=1;j<=m;++j)
		{
			ll pre=0;
			for(int i=1;i<=n;++i)
			{
				if(a[i][j]=='1') {pre=0; continue;}
				ansC = (ansC + (pre-right[i-1][j])*right[i][j]%mod) %mod;
				ansF = (ansF + (pre-right[i-1][j])*right[i][j]%mod*under[i][j]%mod) %mod;
				pre = (pre + right[i][j]);
			}
		}
		write(C*ansC); putchar(' ');
		write(F*ansF); putchar('\n');
	}
}
