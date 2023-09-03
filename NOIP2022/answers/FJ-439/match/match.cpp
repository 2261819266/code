#include <bits/stdc++.h>
using namespace std;
inline long long read() {
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
unsigned long long MOD=(unsigned long long)(pow(2,64));
int t,n,Q;
long long l,r;
long long a[250010],b[250010];
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin >> t >> n;
	for (register int i=1;i<=n;++i) {
		a[i]=read();
	}
	for (register int i=1;i<=n;++i) {
		b[i]=read();
	}
	cin >> Q;
	while(Q--) {
		unsigned long long ans=0LL;
		l=read(),r=read();
		for (int p=l;p<=r;p++) {
			for (int q=p;q<=r;q++) {
				long long maxa=0,maxb=0;
				for (int i=p;i<=q;i++) {
					maxa=max(maxa,a[i]);
					maxb=max(maxb,b[i]);
				}
				ans+=(maxa*maxb)%MOD;
				ans%=MOD;
			}
		}
		cout << ans%MOD << endl;
	}
	return 0;
}
