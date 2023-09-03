#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;
const int MAXN = 310;
const int MAXM = 2000010;
const int MAXK = 610;

int n, m, K, a[MAXN], stk[MAXN][MAXK<<1], top[MAXN], but[MAXN], cur = 1;
bool vis1[MAXK], vis2[MAXK];
int now1[MAXK], now2[MAXK], n1, n2, p1[MAXN], p2[MAXN], ord[MAXN];
pii ans[MAXN], tmp[MAXN];

bool ok = 0;
inline bool check()
{
	for(int i=1;i<=n;i++) if(top[i] >= but[i]) return 0;
	return 1;
}
void dfs(int p, int cnt)
{
	if(ok) return ;
	if(p > m)
	{
//		ok = 1;
//		printf("%d\n",cnt);
//		for(int i=1;i<=cnt;i++)
//		{
//			if(ans[i].first == -1) printf("1 %d\n",ans[i].second);
//			else printf("2 %d %d\n",ans[i].first,ans[i].second);
//		}
		if(check() && cnt <= m*2)
		{
			ok = 1;
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;i++)
			{
				if(ans[i].first == -1) printf("1 %d\n",ans[i].second);
				else printf("2 %d %d\n",ans[i].first,ans[i].second);
			}
		}
		return ;
	}
	if(ok) return ;
	int oc = cnt;
	for(int i=1;i<=n;i++)
	{
		int otop = top[i];
		stk[i][++top[i]] = a[p];
		ans[++cnt] = make_pair(-1, i);
		if(top[i] > but[i] && stk[i][top[i]] == stk[i][top[i]-1])
		{
			top[i] -= 2;
			dfs(p+1, cnt);
			if(ok) return ;
			top[i] = otop;
			cnt = oc;
			continue;
		}
		int ncnt = 0;
//		if(top[i] == but[i])
//		{
//			printf("i = %d, %d\n",i,n);
//			for(int j=1;j<=n;j++)
//			{
//				printf("j = %d : [%d,%d] ",j,but[j],top[j]);
//				for(int k=but[j];k<=top[j];k++) printf("%d ",stk[j][k]);
//				puts("");
//			}
			for(int j=1;j<=n;j++) if(j != i && top[j] >= but[j] && stk[j][but[j]] == stk[i][but[i]]) ++ncnt;
			if(ncnt)
			{
				for(int j=1;j<=n;j++) if(j != i && top[j] >= but[j] && stk[j][but[j]] == stk[i][but[i]])
				{
					ans[++cnt] = make_pair(i, j);
					++but[i]; ++but[j];
					dfs(p+1, cnt);
					if(ok) return ;
					--but[i]; --but[j];
				}
				cnt = oc;
				top[i] = otop;
				continue;
			}
//		}
		dfs(p+1, cnt);
		if(ok) return ;
		top[i] = otop;
		cnt = oc;
	}
	cnt = oc;
}

//void dfs()

inline void work()
{
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) but[i] = 1, top[i] = 0;
	ok = 0;
	dfs(1, 0);
}

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
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
