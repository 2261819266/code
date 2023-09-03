#include<cstdio>
using namespace std;
const int MAXN=305;
const int MAXM=2e6+5;
int t,n,m,k;
int stk[MAXN],a[MAXN];
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

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=m;i++)
			a[i]=read();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
