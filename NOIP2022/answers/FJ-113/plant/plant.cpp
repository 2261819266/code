#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
typedef __int128 LL;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef queue<int> QI;
typedef vector<int> VI;
typedef basic_string<int> BI;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int randint(int a, int b){assert(b >= a); return uniform_int_distribution<int>(a,b)(rnd);}
char buf[1<<21], *p1, *p2;
//#define GC p1 == p2 and (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++
inline int read()
{
	int x = 0, f = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = 1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x<<1)+(x<<3)+(ch^48), ch = getchar();
	return f?-x:x;
}
const int P = 998244353;
inline int GCD(int a, int b){return b ? GCD(b,a%b) : a;}
inline int ADD(){return 0;}
template <typename ...A>
inline int ADD(int a, A...b){int s = ADD(b...); if(a >= P) a -= P; return a+s < 0 ? a+s+P : a+s < P ? a+s : a+s-P;}
inline int MUL(){return 1;}
template <typename ...A>
inline int MUL(int a, A...b){if(a >= P) a -= P; return (ll)a*MUL(b...)%P;}
inline int qpow(int a, int b){int s = 1; if(a >= P) a -= P; for(; b; b >>= 1, a = MUL(a,a)) if(b&1) s = MUL(s,a); return s;}
const int N = 1010;
int T, id, n, m, c, f, nxt[N][N], dwn[N], sum0[N], sum1[N], sum2[N], cntC, cntF; char s[N][N];
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int i, j, k;
	for(T = read(), id = read(); T--; printf("%d %d\n",cntC*c,cntF*f))
	{
		n = read(), m = read(), c = read(), f = read(); cntC = 0, cntF = 0;
		for(i = 1; i <= n; i++) for(scanf("%s",s[i]+1), k = m+1, j = m; j; j--) if(s[i][j] == '1') k = j; else nxt[i][j] = k; 
		for(j = 1; j <= m; j++) 
		{
			for(i = 1; i <= n; i++) sum1[i] = sum2[i] = 0;
			for(k = n+1, i = n; i; i--) if(s[i][j] == '1') k = i; else dwn[i] = k;
			for(i = 1; i <= n; i++) 
			{
				sum2[i] = sum2[i-1], sum1[i] = sum1[i-1];
				if(s[i][j] == '0' && nxt[i][j] > j+1) 
				{
					sum2[i] = ADD(sum2[i],MUL(sum1[i-2],nxt[i][j]-j-1)), sum1[i] = ADD(sum1[i],nxt[i][j]-j-1);
					cntC = ADD(cntC,MUL(sum1[i-2],nxt[i][j]-j-1)), cntF = ADD(cntF,MUL(sum2[i],dwn[i]-i-1));
				}
				else if(s[i][j] == '1') sum1[i-1] = sum1[i] = sum2[i-1] = sum2[i] = 0;	
			}		
		}
	}
	return 0;
}
