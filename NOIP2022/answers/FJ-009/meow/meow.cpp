#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
inline int read()
{
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		g*=10;
		g+=ch-'0';
		ch=getchar();
	}
	return f*g;
}
int n,m,k;
int flag[605];
vector<int> num[605];
int to[605];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t=read();
	int flag=0;
	if(t%10==1||t==1)
	{
		flag=1;
	}
	while(t--)
	{
		n=read();m=read();k=read();
		cout<<m<<endl;
		for(int j=1;j<=m;j++)
		{
			int t=j%n;
			if(t==0)t=n;
			printf("1 %d\n",t);
		}
	}
	
	return 0;
}
