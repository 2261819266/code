#include<bits/stdc++.h>
#define rep(i,a,b) for(int i(a);i<=b;++i)
#define per(i,a,b) for(int i(a);i>=b;--i)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(a,b) a^=b^=a^=b
inline int read()
{
	int x(0),f(1);
	char c=getchar();
	while(c<'0'||c>'9')
	{
		f=(c^'-'?1:-1);
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
using namespace std;
const int N=3e2+5;
mt19937_64 myrand(114514+1919810+time(0));
int T;
struct stack
{
	int st[N*10],floor,top;
	inline void init() {floor=1;top=1;}
	inline int size() {return top-floor+1;}
	inline void pop() {++floor;}
	inline void push(int col)
	{
		if(st[top]==col)
			--top;
		else
			st[++top]=col;
	}
} a[N];
signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--)
	{
		int n=read(),m=read(),k=read();
		rep(i,1,n)
			a[i].init();
		rep(M,1,m)
		{
			int col=read();
			rep(i,1,n)
			{
				rep(j,i+1,n)
				{
					if(a[i].top==a[i].floor||a[j].top==a[j].floor)
						continue;
					if(a[i].st[a[i].floor]==a[j].st[a[j].floor])
					{
						a[i].pop();
						a[j].pop();
						printf("2 %d %d\n",i,j);
					}
				}
			}
			bool tag=1;
			rep(i,1,n)
			{
				if(a[i].top==a[i].floor)
					continue;
				if(a[i].st[a[i].top]==col)
				{
					a[i].push(col);
					printf("1 %d\n",i);
					tag=0;
					break;
				}
			}
			if(tag)
			{
				int now=myrand()%n+1;
				a[now].push(col);
				printf("1 %d\n",now);
			}
		}
	}
	return 0;
}