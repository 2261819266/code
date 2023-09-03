#include <bits/stdc++.h>

using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define ull unsigned long long
const int N = 3e5 + 10;

int T, n,a[N], b[N];
int p1[N],p2[N];
unsigned long long ans[3003][3003];

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out","w",stdout);
	cin >> T>>n;
	rep(i,1,n)cin>>a[i],p1[a[i]]=i;
	rep(i,1,n)cin>>b[i],p2[b[i]]=i;
	rep(i,1,n){
		unsigned long long ans1=0,ans2=0;
		for(int j=i;j<=n;j++){
			ans1=max(ans1,(ull)a[j]);
			ans2=max(ans2,(ull)b[j]);
			ans[i][j]=ans[i][j-1]+ans1*ans2;
		}
	}
	int q;cin>>q;
	while(q--) {
		int l,r;cin>>l>>r;
		unsigned long long a = 0;
		for (int i = l; i <= r; i++) {
			a += ans[i][r];
		}
		cout<<a<<'\n';
	}
	return 0;
}
