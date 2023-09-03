#include<iostream>
#include<cstdio>
#define unsigned long long
const int N = 25e4;
const int M = 1<<64;
int n,t,a[N],b[N];
int q,l,r,ans,ma,mb;
signed main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%u%u", &t, &n);
	for(register int i=1;i<=n;i++){
		scanf("%u", &a[i]);
	}
	for(register int i=1;i<=n;i++){
		scanf("%u", &b[i]);
	}
	scanf("%u", &q);
	while(q--){
		scanf("%u%u", &l, &r);
		ans=0;
		for(register int j=l;j<=r;j++){
			for(register int k=j;k<=r;k++){
				ma=-1e9;mb=-1e9;
				for(register int o=j;o<=k;o++){
					if(ma<a[o])ma=a[o];
					if(mb<b[o])mb=b[o];
				}
				ans=ans+ma*mb;
			}
		}
		if(ans==M)ans=0;
		printf("%u\n", ans);
	}
}
