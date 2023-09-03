#include <bits/stdc++.h>
using namespace std;

int a[250001],b[250001];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	int Q;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		long long sum=0;
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				int maxa=0,maxb=0;
				for(int j=p;j<=q;j++){
					maxa=max(maxa,a[j]);
					maxb=max(maxb,b[j]);
				}
				sum+=(maxa*maxb);
//				printf("%d %d %d\n",p,q,maxa*maxb);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
