#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n,Q;
	scanf("%d %d",&T,&n);
	int a[250005],b[250005];
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	scanf("%d",&Q);
	while(Q--){
		int l,r;
		long long ans=0;
		scanf("%d %d",&l,&r);
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				int maxN=-1,maxO=-1;
				for(int i=p;i<=q;i++){
					maxN=max(maxN,a[i]);
					maxO=max(maxO,b[i]);
				}
				ans+=maxN*maxO;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
