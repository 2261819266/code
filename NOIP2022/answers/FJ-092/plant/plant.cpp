#include<cstdio>
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

const int mod=998244353;
inline int Mod(int x){return x>=mod?x-mod:x;}
inline void Add(int &x,int y){x+=y;if(x>=mod)x-=mod;}

#define N 1010

bool isC,isF;

int n,m;

char a[N][N];

int A[N][N];
int B[N][N];

int Ans=0;

inline int getC()
{
	if(!isC)return 0;
	int res=0;
	for(int j=1;j<=m;j++)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='0')
			{
				Add(res,1ll*sum*(A[i][j]-1)%mod);
				if(a[i-1][j]=='0')Add(sum,A[i-1][j]-1);
			}
			else sum=0;
		}
	}
	return res;
}

inline int getF()
{
	if(!isF)return 0;
	int res=0;
	for(int j=1;j<=m;j++)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='0')
			{
				Add(res,1ll*sum*(A[i][j]-1)%mod*(B[i][j]-1)%mod);
				if(a[i-1][j]=='0')Add(sum,A[i-1][j]-1);
			}
			else sum=0;
		}
	}
	return res;
}

inline void solve()
{
	n=read(),m=read(),isC=read(),isF=read();
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			A[i][j]=B[i][j]=0;	
	Ans=0;
	
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
			A[i][j]=a[i][j]=='0'?A[i][j+1]+1:0,
			B[i][j]=a[i][j]=='0'?B[i+1][j]+1:0;
	
	printf("%d %d\n",getC(),getF());
}

int main()
{
	#define NAME "plant"
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);
	
	int test=read();read();
	for(;test;test--)solve();
	return 0;
}
//Never gonna give you up.
