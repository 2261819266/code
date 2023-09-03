#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 3;

int t,n,q;
int a[N],b[N];

unsigned long long ans = 0;

int lgg[N];
int f1[N][23];
int f2[N][23];

inline int read(){
	int s = 0;char c = getchar();
	while(!isdigit(c)){
		c = getchar();
	}
	while(isdigit(c)){
		s = (s << 1) + (s << 3) + (c ^ 48);
		c = getchar();
	}
	return s;
}

signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t = read(); n = read();
	for(int i = 2;i<=n;i++){
		lgg[i] = lgg[i >> 1] + 1;
	} 
	for(int i = 1;i<=n;i++){
		a[i] = read();
		f1[i][0] = a[i];
	}
	for(int i = 1;i<=n;i++){
		b[i] = read();
		f2[i][0] = b[i];
	}
	for(int i = 1;i<=21;i++){
		for(int j = 1;j + (1 << i) - 1<=n;j++){
			f1[j][i] = max(f1[j][i - 1],f1[j + (1 << (i - 1))][i - 1]);
			f2[j][i] = max(f2[j][i - 1],f2[j + (1 << (i - 1))][i - 1]);
		}
	}
	q = read();
	for(int i = 1;i<=q;i++){
		ans = 0ull;
		int ll,rr;
		ll = read(); rr = read();
		for(int l = ll;l<=rr;l++){
			for(int r = l;r<=rr;r++){
				int s = lgg[r - l + 1];
				ans += max(f1[l][s],f1[r - (1 << s) + 1][s]) * max(f2[l][s],f2[r - (1 << s) + 1][s]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
