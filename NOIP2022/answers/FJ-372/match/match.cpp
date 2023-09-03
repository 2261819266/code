#include <bits/stdc++.h>
#define ll long long
#define pte putchar('\n');
#define pts putchar(' ');
#define gc getchar();
#define max(i,j) (((i)>(j))?(i):(j))
#define min(i,j) (((i)<(j))?(i):(j))
#define abs(i) (((i)<0)?-(i):(i))
ll read() {
	ll a=0, f=1; char c=gc;
	while(c<'0' || c>'9') {
		if(c=='-') f*=-1;
		c=gc;
	}
	while(c>='0' && c<='9') {
		a=(a<<1)+(a<<3)+(c^48), c=gc;
	}
	return a*f;
}
void write(ll x) {
	if(x<0) {putchar('-'); x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

unsigned ll mod=pow(2,64);
int T, n, a[500010], b[500010], Q, l[500010], r[500010];
ll ans;

void input() {
	T=read();
	n=read();
	for(int i=1;i<=n;i++)	a[i]=read(), b[i]=read();
	Q=read();
	for(int i=1;i<=Q;i++)	l[i]=read(), r[i]=read();
	return;
}

void work() {
	for(int i=1;i<=Q;i++) {
		for(int p=l[i];p<=r[i];p++) {
			for(int q=p;q<=r[i];q++) {
				ll maxn=-1, maxo=-1;
				for(int j=p;j<=q;j++)	maxn=max(maxn,a[j]), maxo=max(maxo,b[j]);
				ans=(ans+maxn*maxo)%mod;
			}
		}
	}
	return;
}

void output() {
	write(ans%mod);pte;
	return;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	input();
	work();
	output();
	fclose(stdin);
	fclose(stdout);
}
