#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N   = 2.5*1e5+10;
int a[N][26], b[N][26];
inline int getmx1(int l, int r){
	int tmp=log2(r-l+1);
	return max(a[l][tmp], a[r-(1<<(tmp))+1][tmp]);
}
inline int getmx2(int l, int r){
	int tmp=log2(r-l+1);
	return max(b[l][tmp], b[r-(1<<(tmp))+1][tmp]);
}
int main(){
	
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int t, n;
	scanf("%d%d", &t, &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i][0]);
	for(int i=1;i<=n;i++) scanf("%d", &b[i][0]);
	int q;
	scanf("%d", &q);
	for(int j=1;j<23;j++)
		for(int i=1;i+(1<<(j-1))+1<=n;i++)
			a[i][j]=max(a[i][j-1], a[i+(1<<(j-1))][j-1]),
			b[i][j]=max(b[i][j-1], b[i+(1<<(j-1))][j-1]);
	while(q--){
		int l , r;
		scanf("%d%d", &l, &r);
		unsigned long long ans=0;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++){		
				unsigned long long tmp1=getmx1(p, q), tmp2=getmx2(p, q);
				ans+=(ans+tmp1*tmp2);
			}
		printf("%llu\n", ans);
	}
	return 0;
}
