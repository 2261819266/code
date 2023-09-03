#include<bits/stdc++.h>
using namespace std;
const int N=2.5e5+5;
int n,q,a[N],b[N];
unsigned long long d[3005][3005];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	scanf("%d",&q);
	if(n<=3000&&q<=3000){
		for(int i=1;i<=n;++i)for(int j=i,mx1=0,mx2=0;j<=n;++j)mx1=max(mx1,a[j]),mx2=max(mx2,b[j]),d[i][j]=d[i][j-1]+1ull*mx1*mx2;
		for(int i=1,l,r;i<=q;++i){
			scanf("%d%d",&l,&r);
			unsigned long long res=0;
			for(int j=l;j<=r;++j)res=res+d[j][r];
			printf("%llu\n",res);
		}
	}
	return 0;
}
