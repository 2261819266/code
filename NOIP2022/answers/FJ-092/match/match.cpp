#include<cstdio>
#include<algorithm>
using namespace std;
#define isDigit(ch) ('0'<=ch&&ch<='9')
#define i64 long long
#define u64 unsigned long long
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

inline int gmax(int x,int y){return x>y?x:y;}

#define N 250010
#define M 5005

int n;

int a[N],b[N];

int A[M][M];
int B[M][M];
u64 Ans[M][M];

int main()
{
	#define NAME "match"
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);
	
	read();n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	for(int i=1;i<=n;i++)
	{
		int mxA=0,mxB=0;
		for(int j=i;j<=n;j++)
			mxA=gmax(mxA,a[j]),
			mxB=gmax(mxB,b[j]),
			Ans[i][j]=1ull*mxA*mxB;
	}
	for(int i=2;i<=n;i++)
		for(int l=1,r=i;r<=n;l++,r++)
			Ans[l][r]+=Ans[l][r-1]+Ans[l+1][r]-Ans[l+1][r-1];
	for(int q=read(),l,r;q;q--)
	{
		l=read(),r=read();
		printf("%llu\n",Ans[l][r]);
	}
	return 0;
}
//Never gonna give you up.
