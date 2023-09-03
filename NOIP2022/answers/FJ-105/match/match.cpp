#include<bits/stdc++.h>
using namespace std;
int T,n,Q,a[300010],b[300010],inl,inr,maxa=-1,maxb=-1;
unsigned long long ans,cs=1;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	scanf("%d",&Q);
	while(Q--){
		ans=0;
		scanf("%d%d",&inl,&inr);
		for(int p=inl;p<=inr;p++){
			for(int q=p;q<=inr;q++){
				maxa=-1,maxb=-1;
				for(int i=p;i<=q;i++){
					maxa=max(maxa,a[i]);
					maxb=max(maxb,b[i]);
				}
				ans+=cs*maxa*maxb;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
2 1
1 2
5
1 2
1 2
1 2
1 2
1 2
*/
