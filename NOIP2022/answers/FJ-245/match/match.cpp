#include<bits/stdc++.h>
using namespace std;
int t,n,q,l,r;
int a[1000007],b[1000007];
int maxa,maxb;
long long ans;
inline int read() {
	int x=0;
	bool f=0;
	char ch=getchar();
	for(; !isdigit(ch); ch=getchar()) f|=(ch=='-');
	for(; isdigit(ch); ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	if(f) x=-x;
	return x;
}
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();
	n=read();
	for(int i=1; i<=n; i++) {
		a[i]=read();
	}
	for(int i=1; i<=n; i++) {
		b[i]=read();
	}
	q=read();
	for(int i=1; i<=q; i++) {
		l=read();
		r=read();
		for(int k=r; k>=l; k--)
			for(int j=l; j<=r; j++) {
				for(int i=j; i<=k; i++) {
					maxa=max(a[i],maxa);
					maxb=max(b[i],maxb);
				}
				ans+=maxa*maxb;
				maxa=0;
				maxb=0;
			}
		cout<<ans-ans/(1<<16)/(1<<16)/(1<<16)/(1<<16)*(1<<16)*(1<<16)*(1<<16)*(1<<16);
	}

	return 0;
}
