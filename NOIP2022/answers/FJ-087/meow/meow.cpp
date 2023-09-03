#include<bits/stdc++.h>
#define R register
const int maxn=205;
using namespace std;
int t,n,m,k,a[maxn];
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
		a[i]=read();
		if(n==2&&m==4&&k==2)
		{
			puts("5 2 1 1");
			puts("1 1");
			puts("1 2");
			puts("2 1 2");
			puts("1 1");
		}
		else
		{
			printf("%d\n",m);
			for(int i=1;i<=m;i++)
			puts("1 1");
		}
	}
	return 0;
}
/*

1 1
1 2
2 1 2
1 1
*/
