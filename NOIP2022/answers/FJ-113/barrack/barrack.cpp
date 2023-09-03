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
const int P = 1e9+7;
inline int GCD(int a, int b){return b ? GCD(b,a%b) : a;}
inline int ADD(){return 0;}
template <typename ...A>
inline int ADD(int a, A...b){int s = ADD(b...); if(a >= P) a -= P; return a+s < 0 ? a+s+P : a+s < P ? a+s : a+s-P;}
inline int MUL(){return 1;}
template <typename ...A>
inline int MUL(int a, A...b){if(a >= P) a -= P; return (ll)a*MUL(b...)%P;}
inline int qpow(int a, int b){int s = 1; if(a >= P) a -= P; for(; b; b >>= 1, a = MUL(a,a)) if(b&1) s = MUL(s,a); return s;}
const int N = 5e5+5, M = 2e6+5;
int n, m, tot, top, ans, Flag, head[N], ver[M], nxt[M], sz[N], v[N], pre[N], pow2[M], op[2][M]; VI g;
inline void add(int x, int y){ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;}
inline void dfs1(int x, int fr)
{
	int i, y; sz[x] = 1;
	for(i = head[x]; i; i = nxt[i]) if((y = ver[i]) != fr) dfs1(y,x), sz[x] += sz[y];
	ans = ADD(ans,-MUL(ADD(pow2[sz[x]],-1),ADD(pow2[n-sz[x]],-1)));
}
signed main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int i, j, x, y, cnt, tmp, flag;
	for(pow2[0] = i = 1; i <= 2e6; i++) pow2[i] = MUL(pow2[i-1],2); 
	n = read(), m = read(), flag = 1, ans = 0;
	for(i = 1; i <= m; i++){x = read(), y = read(), add(x,y), add(y,x), op[0][i] = x, op[1][i] = y; if(abs(x-y) != 1) flag = 0;}
	if(flag) for(i = 1; i <= n; i++) ans = ADD(ans,MUL(n-i+1,pow2[m-i+1]));
	else
	{
		if(m == n-1) ans = MUL(ADD(pow2[n],-1),pow2[m]), dfs1(1,1);
		if(m <= 20)
		{
			ans = MUL(n,pow2[m]);
			for(i = 1; i < (1<<m); i++)
			{
				for(j = 1; j <= n; j++) v[j] = 0;
				for(j = 1; j <= m; j++) if(i&(1<<(j-1))) v[op[0][j]] = v[op[1][j]] = 1;
				for(j = 1, cnt = 0; j <= m; j++) if(v[j]) cnt++;
				ans = ADD(ans,pow2[cnt],-1-cnt);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
