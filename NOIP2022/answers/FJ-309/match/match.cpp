#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){
		ch = getchar();
		f = -1;
	}
	while(isdigit(ch)){
		X = (X<<1)+(X<<3)+ch-'0';
		ch = getchar();
	}
	return f*X;
}

const int N = 5100;
int n;
int a[N],b[N];
int m1[N][N],m2[N][N];

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T = read();
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++) b[i] = read();
	for(int i=1;i<=n;i++){
		m1[i][i] = a[i];
		for(int j=i+1;j<=n;j++)
			m1[i][j] = max(m1[i][j-1],a[j]);
	}
	for(int i=1;i<=n;i++){
		m2[i][i] = b[i];
		for(int j=i+1;j<=n;j++)
			m2[i][j] = max(m2[i][j-1],b[j]);
	}
	int Q = read();
	while(Q--){
		int l,r;
		l = read();
		r = read();
		ll ans = 0;
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++){
				ans += m1[p][q]*m2[p][q];
			}
		cout << ans << "\n";
	}
	return 0;
}
