#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500005, M=1000000007;
ll clr[N], clr_n=0, low[N], dfn[N], cnt=0, crn[N], out[N];
ll zh[3005][3005];
bool ins[N];
stack<ll>sk;
struct p{
	vector<ll>ut;
};
p ps[N], nps[N];
void tarjan(ll now, ll f){
	low[now] = dfn[now] = ++cnt;
	ins[now] = true;
	sk.push(now);
	for (ll t:ps[now].ut){
		if (t == f)continue;
		if (not dfn[t]){
			tarjan(t, now);
			low[now] = min(low[now], low[t]);
		} else {
			if (ins[t]){
				low[now] = min(low[now], dfn[t]);
			}
		}
	}
	if (low[now] == dfn[now]){
		++clr_n;
		while (sk.top() != now){
			clr[sk.top()] = clr_n;
			++crn[clr_n];
			ins[sk.top()] = false;
			sk.pop();
		}
		clr[sk.top()] = clr_n;
		++crn[clr_n];
		ins[sk.top()] = false;
		sk.pop();
	}
}
ll tgs=1, ans=0, mn;
ll oh(ll p){
	ll res=1;
	for (ll x=1;x<=p;++x){
		res *= 2;
		res %= M;
	}
	return res;
}
void dfs(ll cp, ll csv, ll now, ll f, ll ot, ll ens, bool lt){
	if (csv == tgs or (csv-crn[clr[f]] < tgs and csv > tgs)){
		ans = (ans+zh[csv][tgs+1]*(oh(mn-ens+lt)))%M;
	}
	if (cp > clr_n)return;
	bool b=true;
	for (ll t:nps[now].ut){
		if (t == f)continue;
		b = false;
		dfs(cp, csv, t, now, ot+1, ens, false);
		dfs(cp+1, csv+crn[now], t, now, ot+1, ot+1, true);
	}
	if (b){
		if (csv+crn[clr[now]] == tgs){
		ans = (ans+zh[csv+crn[clr[now]]][tgs+1]*(oh(mn-ens)))%M;
	}
	}
}
int main(){
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	ll n, m, ta, tb;
	scanf("%lld %lld", &n, &m);
	mn = m;
	for (ll x=1;x<=m;++x){
		scanf("%lld %lld", &ta, &tb);
		ps[ta].ut.push_back(tb);
		ps[tb].ut.push_back(ta);
	}
	zh[0][1] = 1;
	for (ll y=1;y<=1500;++y){
		for (ll x=0;x<=1500;++x){
			zh[y][x] = zh[y-1][x];
			if (x)zh[y][x] += zh[y-1][x-1];
			zh[y][x] %= M;
		}
	}
	tarjan(1, 0);
	for (ll x=1;x<=n;++x){
		for (ll t:ps[x].ut){
			if (clr[x] == clr[t]){
				++out[clr[x]];
				continue;
			}
			
			nps[clr[x]].ut.push_back(clr[t]);
			
		}
	}
//	cout << clr_n << endl;
	for (ll x=1;x<=n;++x){
		tgs = x;
		dfs(0, 0, 1, 0, 0, 0, false);
	}
	
	cout << ans;
}
