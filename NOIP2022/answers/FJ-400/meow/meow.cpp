#include <bits/stdc++.h>
using namespace std;
#define enter putchar('\n')
#define kkk putchar(' ')
const int N=307,K=607,M=2e6+7;
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
void write(int x)
{
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
deque<int>p[N];
int ans[M],s1[M],s2[M];
int n,m,k;
int a[M];
int num[K];
int op;
void cz1(int x)
{
	op++;
	ans[op]=1,s1[op]=x;
}
void cz2(int x,int y)
{
	op++;
	ans[op]=2;
	s1[op]=x,s2[op]=y;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;T=read();
	while(T--)
	{
		op=0;
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)a[i]=read();
		if(k==2*n-2)
		{
			for(int i=1,j;i<=m;i++)
			{
				j=(a[i]-1)/2+1;
				if(!num[a[i]])
				{
					cz1(j);
					num[a[i]]++;
					p[j].push_back(a[i]);
				}
				else if(p[j].back()==a[i])
				{
					cz1(j);
					num[a[i]]--;
					p[j].pop_back();
				}
				else
				{
					cz1(n);
					cz2(j,n);
					num[a[i]]--;
					p[j].pop_front();
				}
			}
			write(op),enter;
			for(int i=1;i<=op;i++)
			{
				write(ans[i]),kkk;
				if(ans[i]==1)
					write(s1[i]),enter;
				else 
				{
					write(s1[i]),kkk;
					write(s2[i]),enter;
				}
			}
		}
	}
	return 0;
}
