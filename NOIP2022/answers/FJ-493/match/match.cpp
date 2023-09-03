#include<bits/stdc++.h>
using namespace std;
int T,n,q;
int a[250005],b[250005];
unsigned long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int i1=l;i1<=r;i1++){
			for(int j1=i1;j1<=r;j1++){
				long long maxa=-1,maxb=-1;
				for(int i3=i1;i3<=j1;i3++)maxa=max(maxa,(long long)a[i3]);
				for(int j3=i1;j3<=j1;j3++)maxb=max(maxb,(long long)b[j3]);
				ans+=maxa*maxb;
			}
		} 
		printf("%lld\n",ans);
	}
	return 0;
}
