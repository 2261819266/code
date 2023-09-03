#include <bits/stdc++.h>
using namespace std;
const int N=2.5e5+7,lg=25;
int read()
{
	int x=0,y=1;char ch;
	do{ch=getchar();
	if(ch=='-')y=-1;
	}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*y;
}
void write(unsigned long long x)
{
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n;
int a[N],b[N];
int ac[N][lg],bc[N][lg];
int t;
unsigned long long ans;
void pre_work()
{
	for(int i=1;i<=n;i++)
		ac[i][0]=a[i],bc[i][0]=b[i];
	for(int i=1;i<=t;i++)
		for(int j=1;j<=n;j++)
		{
			ac[j][i]=max(ac[j+(1<<(i-1))][i-1],ac[j][i-1]);
			bc[j][i]=max(bc[j+(1<<(i-1))][i-1],bc[j][i-1]);
		}
}
int ga(int l,int r)
{
	int h=log(l-r+1)/log(2);
	return max(ac[l][h],ac[r-(1<<h)+1][h]);
}
int gb(int l,int r)
{
	int h=log(l-r+1)/log(2);
	return max(bc[l][h],bc[r-(1<<h)+1][h]);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,Q;
	T=read(),n=read();
	T--;T++;
	t=log(n)/log(2);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int j=1;j<=n;j++)b[j]=read();
	pre_work();
	Q=read();
	int l,r;
	while(Q--)
	{
		ans=0ull;
		l=read(),r=read();
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++)
				ans=ans+ga(i,j)*gb(i,j);
		write(ans),putchar('\n');
	}
	return 0;
}
