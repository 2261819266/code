#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define isDigit(ch) ('0'<=ch&&ch<='9')
#define i64 long long
inline int read()
{
	int num=0;
	char ch=getchar();
	while(!isDigit(ch))
		ch=getchar();
	while(isDigit(ch))
	{
		num=num*10+(ch-'0');
		ch=getchar();
	}
	return num;
}

#define N 305
#define M 2000010

#define sz(S) ((int)S.size())

int n,m,K;

int a[M];

int ans=0;
bool opt[M<<1];
int x[M<<1];
int y[M<<1];

vector<int> A[N];
int L[N];

int s[N][2];

inline void push(bool opt0,int x0,int y0=0){ans++,opt[ans]=opt0,x[ans]=x0,y[ans]=y0;}

inline void solve1()
{
	for(int i=1;i<=m;i++)
	{
		int j=a[i]>>1;
		if(s[j][0]==a[i])
			push(1,n),push(0,j,n),
			s[j][0]=s[j][1],s[j][1]=0;
		else
		{
			push(1,j);
			if(s[j][1]==a[i])
				s[j][1]=0;
			else if(!s[j][0])
				s[j][0]=a[i];
			else
				s[j][1]=a[i];
		}
	}
}

inline void solve()
{
	n=read(),m=read(),K=read();
	for(int i=1;i<=m;i++)
		a[i]=read()+1;
	for(int i=1;i<=n;i++)
		s[i][0]=s[i][1]=0;
	solve1();
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		if(opt[i])printf("1 %d\n",x[i]);
		else printf("2 %d %d\n",x[i],y[i]);
}

int main()
{
	#define NAME "meow"
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);
	
	for(int test=read();test;test--)
		solve();
	return 0;
}
//Never gonna give you up.
