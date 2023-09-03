#include<bits/stdc++.h>
using namespace std;
constexpr int N=103,M=2000003,P=1e9+7; 
bool Mbe;
inline int read()
{
	int x=0,y=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-') y=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*y;
}

char OU[30];
short CC;
inline void write(int x)
{
	CC=0;
	if(x==0) return putchar('0'),void();
	while(x) OU[++CC]=x%10+'0',x/=10;
	while(CC) putchar(OU[CC--]);
}

mt19937 rnd(1239);
int n,m,K,a[N],pos;

//n 个zhan
//m 张牌
//k zhiyu
/*
两个相同，扔掉
所以加进去的时候一定跟上一次不同
留一个空栈，如果栈顶有跟 x 一样的往那里加1
如果栈底有往空的加，然后那个扔掉。 

 
*/
int ans;
deque<int> s[N];
inline void solve()
{
	n=read(),m=read(),K=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++) s[i].clear();ans=0;
//	printf("%d\n",ans);
	for(int i=1;i<=m;i++)
	{
//		printf("   %d\n",i);
		if(i<m&&a[i]==a[i+1])
		{
			ans+=2;
//			putchar('1'),putchar(' '),putchar('1'),putchar('\n');
//			putchar('1'),putchar(' '),putchar('1'),putchar('\n');
			i++;continue;
		}
		else
		{
			bool flag=0;
			for(int j=2;j<=n;j++)
			{
				if(s[j].empty()) continue;
//				printf("%d %d %d\n",s[j].back(),s[j].front(),a[i]);
				if(s[j].back()==a[i])
				{
					++ans,s[j].pop_back();
//					putchar('1'),putchar(' '),write(j),putchar('\n');
					flag=1;break;
				}
				if(s[j].front()==a[i])
				{
					ans+=2;
//					putchar('1'),putchar(' '),write(1),putchar('\n');
////					printf("%d\n",j);
//					putchar('2'),putchar(' '),write(1),putchar(' '),write(j),putchar('\n');
					s[j].pop_front();
					flag=1;break;
				}
			}
			if(flag==1) continue;
//			puts("odfjajds");
			for(int j=2;j<=n;j++)
			{
				if(s[j].size()<=1)
				{
					++ans,s[j].push_back(a[i]),flag=1;
//					putchar('1'),putchar(' '),write(j),putchar('\n');
					break;
				}
			}
			if(!flag)
			{
				ans++;
				s[pos=rnd()%(n-1)+2].push_back(a[i]);
//				putchar('1'),putchar(' '),write(pos),putchar('\n');
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)
	{
//		printf("   %d\n",i);
		if(i<m&&a[i]==a[i+1])
		{
			ans+=2;
			putchar('1'),putchar(' '),putchar('1'),putchar('\n');
			putchar('1'),putchar(' '),putchar('1'),putchar('\n');
			i++;continue;
		}
		else
		{
			bool flag=0;
			for(int j=2;j<=n;j++)
			{
				if(s[j].empty()) continue;
//				printf("%d %d %d\n",s[j].back(),s[j].front(),a[i]);
				if(s[j].back()==a[i])
				{
					++ans,s[j].pop_back();
					putchar('1'),putchar(' '),write(j),putchar('\n');
					flag=1;break;
				}
				if(s[j].front()==a[i])
				{
					ans+=2;
					putchar('1'),putchar(' '),write(1),putchar('\n');
//					printf("%d\n",j);
					putchar('2'),putchar(' '),write(1),putchar(' '),write(j),putchar('\n');
					s[j].pop_front();
					flag=1;break;
				}
			}
			if(flag==1) continue;
//			puts("odfjajds");
			for(int j=2;j<=n;j++)
			{
				if(s[j].size()<=1)
				{
					s[j].push_back(a[i]),flag=1;
					putchar('1'),putchar(' '),write(j),putchar('\n');
					break;
				}
			}
			if(!flag)
			{
				ans++;
				s[pos=rnd()%(n-1)+2].push_back(a[i]);
				putchar('1'),putchar(' '),write(pos),putchar('\n');
			}
		}
	}
}
/*
1 1
2 2 4 2
3 1 2 1 2
*/
bool Med;
signed main()
{
	#define Marsrayd
	#ifdef Marsrayd
		freopen("meow.in","r",stdin);
		freopen("meow.out","w",stdout);
	#endif
	int T=read();while(T--) solve();
	return 0;
}

