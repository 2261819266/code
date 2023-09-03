#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef unsigned long long ull;
const int MAXN=250005;
int t,n,Q;
int a[MAXN],b[MAXN];
ull ans;
int read()
{
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return f*s;
}
void print(ull s)
{
	if(s>9)
		print(s/10);
	putchar(s%10+'0');
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	Q=read();
	for(int i=1;i<=Q;i++)
	{
		ans=0;
		int l=read(),r=read();
		for(int p=l;p<=r;p++)
		{
			int maxa=0,maxb=0;
			for(int q=p;q<=r;q++)
			{//cout<<a[q]<<" "<<b[q]<<endl;
				maxa=max(maxa,a[q]);
				maxb=max(maxb,b[q]);
				ans+=(ull)maxa*maxb;
			}
		}
		print(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
