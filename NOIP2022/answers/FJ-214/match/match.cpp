#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = a; i <= b; i++)
#define int unsigned long long
#define pair<int,int> pii
int a[300010],b[300010];
struct query{
int l,r;
}c[300010];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);	
	int T,n;cin>>T>>n;
	f(i,1,n){
		cin>>a[i];
	}
	f(i,1,n)cin>>b[i];
	int q;cin>>q;
	f(i,1,q){
		cin>>c[i].l>>c[i].r;
		int ans = 0;
		f(P,c[i].l,c[i].r){
			f(Q,P,c[i].r){
				int lm=0,rm=0;
				f(pp,P,Q)lm=max(lm,a[pp]);
				f(pp,P,Q)rm=max(rm,b[pp]);
				ans+=lm*rm;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

