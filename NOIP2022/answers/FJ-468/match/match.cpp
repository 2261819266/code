#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rint register int
int N[300000],O[300000];
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	scanf("%d%d",&T,&n);
	for(int i=1; i<=n; i++)scanf("%d",&N[i]);
	for(int i=1; i<=n; i++)scanf("%d",&O[i]);
	int Q;
	scanf("%d",&Q);
	while(Q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		ull ans=0;
		for(int p=l; p<=r; p++) {
			for(int q=p; q<=r; q++) {
				ull MAXN=0,MAXO=0;
				for(int i=p; i<=q; i++)MAXN=max(MAXN,(unsigned long long)N[i]),MAXO=max(MAXO,(unsigned long long)O[i]);
				ans+=MAXN*MAXO;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//11:50 finish

