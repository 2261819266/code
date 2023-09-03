#include<bits/stdc++.h>
using namespace std;
const int N=3*1e5;
int a[N],b[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int l,r;
		unsigned long long ans=0;
		scanf("%d%d",&l,&r);
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++){
				int res1=0,res2=0;
				for(int i=p;i<=q;i++) res1=max(res1,a[i]);
				for(int i=p;i<=q;i++) res2=max(res2,b[i]);
				unsigned long long t=(res1*res2);
				ans+=t;
			}
		printf("%llu\n",ans);
	}
	return 0;
}
