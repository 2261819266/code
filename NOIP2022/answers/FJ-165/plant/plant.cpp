#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1010;
const int MOD = 998244353;

inline int add(int a, int b) { return (a+=b)>=MOD?a-MOD:a;}
inline void inc(int& a, int b) { a = add(a, b);}

int n, m;
//struct bit{
//	int t[MAXN];
//	inline void reset() { memset(t, 0, (n+2)<<2);}
//	inline void upd(int x, int v) { for(;x<=n;x+=(x&(-x))) t[x] += v;}
//	inline int qry(int x)
//};

int a[MAXN][MAXN], d[MAXN][MAXN], b[MAXN][MAXN], C, F, w[MAXN];
char in[MAXN];

inline void work()
{
	scanf("%d%d%d%d",&n,&m,&C,&F); getchar();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",in+1);
		for(int j=1;j<=m;j++) a[i][j] = in[j]-'0', b[i][j] = d[i][j] = 0;
	}
	for(int i=1;i<=n;i++) a[i][m+1] = 1;
	for(int i=1;i<=m;i++) a[n+1][i] = 1;
//	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) printf("%d%c",a[i][j]," \n"[j==m+1]);
	int ansc = 0, ansf = 0;
	for(int i=1;i<=n;i++) for(int j=m;j;j--)
	{
		if(a[i][j]) d[i][j] = 0;
		else d[i][j] = d[i][j+1] + 1;
	}
	for(int j=1;j<=m;j++) for(int i=n;i;i--)
	{
		if(a[i][j]) b[i][j] = 0;
		else b[i][j] = b[i+1][j] + 1;
	}
//	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) printf("%d%c",d[i][j]," \n"[j==m+1]);
//	puts("");
//	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) printf("%d%c",b[i][j]," \n"[j==m+1]);
//	puts("");
	for(int j=1;j<=m;j++)
	{
		memset(w, 0, (n+2)<<2);
		for(int i=1,s=0;i<=n;i++)
		{
			s += w[i];
			if(d[i][j] > 1)
			{
//				printf("%d %d : %d %d\n",i,j,s,d[i][j]-1);
				ansc += 1ll*s*(d[i][j]-1)%MOD;
				if(!a[i+1][j] && b[i][j] > 1) ansf += 1ll*s*(d[i][j]-1)%MOD*(b[i][j]-1)%MOD;
				if(i+2 <= i+b[i][j]-1) w[i+2] += d[i][j]-1, w[i+b[i][j]] -= d[i][j]-1;
			}
		}
	}
	if(C) printf("%d ",ansc);
	if(F) printf("%d\n",ansf);
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T;
	scanf("%d%*d",&T);
	while(T--) work();
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
