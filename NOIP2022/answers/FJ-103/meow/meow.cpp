//afo
#include <bits/stdc++.h>
#define ll long long
#define fs first
#define sc second
using namespace std;
const int N = 305, M = 2e6+5;
int T;
int n,m,k;
int a[M],nxt[M],lst[N<<1],tg[M];
int res[M];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=m; i++) scanf("%d",&a[i]);
		for(int i=1; i<=k; i++) lst[i]=n+1;
		for(int i=m; i; i--) nxt[i]=lst[a[i]],lst[a[i]]=i;
		for(int i=m; i; i--) tg[i]=!tg[nxt[i]];
		puts("!!!!");	
	}
	return 0;
}

