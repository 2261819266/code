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
const int N = 310, M = 4e6+5;
int T, n, m, k, num, A[M], ans[5][M]; VI st[N];
signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int i, j, a, col, cnt;
	for(T = read(); T--;)
	{
		num = 0; n = read(), m = read(), k = read();
		if(k == (n-1)*2)
		{
			for(i = 1; i <= m; i++) 
			{
				if((a = read()) >= n) col = a-n+1; else col = a;
 				if((cnt = sz(st[col])))
				{
					if((*--st[col].end()) == a) ans[1][++num] = 1, ans[2][num] = col, st[col].erase(--st[col].end());
					else if(cnt > 1) 
					{
						ans[1][++num] = 1, ans[2][num] = n; ans[1][++num] = 2, ans[2][num] = col, ans[3][num] = n;
						st[col].erase(st[col].begin());
					}
					else ans[1][++num] = 1, ans[2][num] = col, st[col].pb(a);
				}
				else ans[1][++num] = 1, ans[2][num] = col, st[col].pb(a);
			}
			for(printf("%d\n",num), i = 1; i <= num; i++, puts("")) for(j = 1; ans[j][i]; ans[j++][i] = 0) printf("%d ",ans[j][i]);
		}
		else
		{
			if(n == 2)
			{
				for(i = 1; i <= m; i++) A[i] = read();	
				for(i = 1; i <= m; i++)
				{
					if(A[i] == (*--st[1].end())) ans[1][++num] = 1, ans[2][num] = 1, st[1].erase(--st[col].end());
					else if(A[i] == (*--st[2].end())) ans[1][++num] = 1, ans[2][num] = 2, st[2].erase(--st[col].end());
					else 
					{
						if(!sz(st[1]) && (*st[2].begin()) == A[i]) 
						{
							ans[1][++num] = 1, ans[2][num] = 1, ans[1][++num] = 2, ans[2][num] = 1, ans[3][num] = 2;
							st[2].erase(*st[2].begin());
						}
						if(!sz(st[2]) && (*st[1].begin()) == A[i])
						{
							
						}
					}
				}
			}
		}
	}
	return 0;
}
