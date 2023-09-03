#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m ,cn;
deque<ll>t[123];
struct op{
	ll o, a, b;
};
vector<op>ps;
bool dfs(stack<ll>cds){
	if (cds.empty()){
		bool ys=true;
		for (ll x=1;x<=n;++x){
			if (not t[x].empty()){
				ys = false;
				break;
			}
		}
		if (ys)return true;
	}
	if (not cds.empty()){
	for (ll x=1;x<=n;++x){
		ll tm=cds.top();
		if (cds.top() == t[x].front()){
			t[x].pop_front();
			cds.pop();
			if (dfs(cds)){
				ps.push_back((op){1, x, 0});
				return true;
			}
			cds.push(tm);
			t[x].push_front(tm);
		} else {
		
		t[x].push_front(cds.top());
		cds.pop();
		if (dfs(cds)){
			ps.push_back((op){1, x});
			return true;
		}
		cds.push(t[x].front());
		t[x].pop_front();
		}
	}
	}
	for (ll x=1;x<=n;++x){
		for (ll y=x+1;y<=n;++y){
			if (t[x].empty() or t[y].empty())continue;
			if (t[x].back() == t[y].back()){
				ll tm=t[x].back();
				t[x].pop_back();
				t[y].pop_back();
				if (dfs(cds)){
					ps.push_back((op){2, x, y});
					return true;
				}
				t[x].push_back(tm);
				t[y].push_back(tm);
			}
		}
	}
	return false;
}


int main(){
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	ll t, tp;
	scanf("%lld", &t);
	deque<ll>cds;
	while (t--){
		cds.clear();
		scanf("%lld %lld %lld", &n, &m, &cn);
		for (ll x=1;x<=m;++x){
			scanf("%lld", &tp);
			cds.push_back(tp);
		}
	}
	stack<ll>sk;
	for (ll x=n-1;x>=0;--x){
		sk.push(cds[x]);
	}
	dfs(sk);
	for (ll x=ps.size()-1;x>=0;--x){
		if (ps[x].o == 1){
			printf("%lld %lld\n", ps[x].o, ps[x].a);
		} else {
			printf("%lld %lld %lld\n", ps[x].o, ps[x].a, ps[x].b);
		}
	}
}
