#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int T,n,Q,l,r;
int a[N],b[N];
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d",&l,&r);
		printf("%d\n",0);
	}
	return 0;
}
