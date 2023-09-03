#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = a; i <= b; i++)
#define int long long
int a[2000010];int n,m,k;
int cnt[710];
int sy[710];//属于哪个栈 
int sx[710];//上还是下？ 
int stk[710];
struct mod {
	int typ; int s,s1,s2;
};
void sol1() {
	vector<mod> v;
	f(i,1,k)sy[i]=sx[i]=stk[i]=0;
	f(i, 1, m ){
		if(sy[a[i]]){
			if(stk[sy[a[i]]] == a[i]){
				v.push_back({1,sy[a[i]], 0, 0});	
				stk[sy[a[i]]] = ((a[i] - 1) ^ 1) + 1;
				sy[a[i]]=0;
			}
			else {
				v.push_back({1,n, 0, 0});
				v.push_back({2,0,sy[a[i]], n});
				sy[a[i]]=0;
			}
		} 
		else {
			sy[a[i]] = ((a[i]+1) / 2);
			v.push_back({1,sy[a[i]],0,0});
			stk[sy[a[i]]] = a[i];
		}
		
	}
	cout << v.size() << endl;
	for(mod x : v) {
		cout << x.typ <<" ";
		if(x.typ == 1) {
			cout << x.s << endl;
		}
		else cout << x.s1<<" "<<x.s2<<endl;
	}
/*
2
2 4 2
1 2 1 2
3 18 4
1 1 2 3 1 4 1 4 1 4 2 3 2 3 4 3 2 1


*/
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);	
	int T; cin >> T;
	while(T--) {
		cin>>n>>m>>k;
		f(i,1,m)cin>>a[i];
		f(i,1,k)cnt[i]=0;
		if(k == 2*n-2){
			sol1();
		}
		
		
	}
	return 0;
}
/*
1
3 20 5
3 1 2 3 4 3 4 5 1 2 4 5 1 3 2 1 1 2 1 4
*/
