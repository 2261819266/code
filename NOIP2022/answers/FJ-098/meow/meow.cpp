#include <bits/stdc++.h>
using namespace std;

int t;
int n, m, k;
int a[1000005];
int ct[301];
int x[30];

inline int read() {
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
	return f*s;
}
#define pb push_back

bool flag = false;

void dfs(int step) {
	if(flag) return;
	if(step == m + 1) {
		deque<int> q[5];
		vector<string> ans;
		for(int i = 1; i <= m; i ++) {
			string s = "1 " + to_string(x[i]); ans.push_back(s);
			if(q[x[i]].size()) {
				if(a[i] == q[x[i]].back()) q[x[i]].pop_back();
				else q[x[i]].push_back(a[i]);
			}
			else {
				q[x[i]].push_back(a[i]);
				for(int j = 1; j <= 3; j ++) {
					if(x[i] == j) continue;
					if(a[i] == q[j].front()) {
						s = "2 " + to_string(min(x[i], j)) + " " + to_string(max(x[i], j));
						ans.push_back(s);
						q[x[i]].pop_back();
						q[j].pop_front();
						break;
					}
				}
			}
		}
		if(!q[1].size() && !q[2].size() && !q[3].size()) {
			flag = true;
			cout << ans.size() << endl;
			for(auto s : ans) cout << s << endl;
		}
		return;
	}
	if(flag) return;
	for(int i = 1; i <= 3; i ++) {
		if(flag) return;
		x[step] = i;
		dfs(step + 1);
		if(flag) return;
		x[step] = 0;
		if(flag) return;
	}
}


void dfss(int step) {
	if(flag) return;
	if(step == m + 1) {
		deque<int> q[n];
		vector<string> ans;
		for(int i = 1; i <= m; i ++) {
			string s = "1 " + to_string(x[i]); ans.push_back(s);
			if(q[x[i]].size()) {
				if(a[i] == q[x[i]].back()) q[x[i]].pop_back();
				else q[x[i]].push_back(a[i]);
			}
			else {
				q[x[i]].push_back(a[i]);
				for(int j = 1; j <= n; j ++) {
					if(x[i] == j) continue;
					if(a[i] == q[j].front()) {
						s = "2 " + to_string(min(x[i], j)) + " " + to_string(max(x[i], j));
						ans.push_back(s);
						q[x[i]].pop_back();
						q[j].pop_front();
						break;
					}
				}
			}
		}
		bool book = true;
		for(int i = 1; i <= n; i ++) {
			if(!q[i].size()) {
				book = false; break;
			}
		}
		if(book) {
			flag = true;
			cout << ans.size() << endl;
			for(auto s : ans) cout << s << endl;
		}
		return;
	}
	if(flag) return;
	for(int i = 1; i <= n; i ++) {
		if(flag) return;
		x[step] = i;
		dfs(step + 1);
		if(flag) return;
		x[step] = 0;
		if(flag) return;
	}
}

int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin >> t;
	if(t % 10 == 1) {
		while(t --) {
			memset(ct, 0, sizeof ct);
			priority_queue<int, vector<int>, greater<int> > q;
			vector<string> ans;
			n = read(), m = read(), k = read();
			int op = m;
			for(int i = 1; i <= m; i ++) a[i] = read();
			for(int i = 1; i <= n - 1; i ++) {
				q.push(i), q.push(n + i);
			}
			for(int i = 1; i <= m; i ++) {
				if(!ct[a[i]]) {
					int p = q.top(); q.pop();
					if(p > n) {
						string s = "1 ";
						s += to_string(p - n);
						ans.pb(s);
						//cout << "1 " << p - n << endl;
					}
					else {
						string s = "1 ";
						s += to_string(p);
						ans.pb(s);
						//cout << "1 " << p << endl;
					}
					ct[a[i]] = p;
				}
				else {
					if(ct[a[i]] > n) {
						string s = "1 ";
						s += to_string(ct[a[i]] - n);
						ans.pb(s);
						//cout << "1 " << ct[a[i]] - n << endl;
					}
					else {
						op ++;
						string s = "1 ";
						s += to_string( n);
						ans.pb(s);
						string ss = "2 ";
						ss += to_string(ct[a[i]]) + " " + to_string(n);
						ans.pb(ss);
						//cout << "1 " << n << endl;
						//cout << "2 " << ct[a[i]] << " " << n << endl;
					}
					q.push(ct[a[i]]); ct[a[i]] = 0;
				}
			}
			cout << op << endl;
			for(auto s : ans) {
				cout << s << endl;
			}
		}
	}
	else if(t % 10 == 2) {
		while(t --) {
			n = read(), m = read(), k = read();
			deque<int> st;
			for(int i = 1; i <= m; i ++) a[i] = read();
			vector<string> ans;
			int l = 2;
			st.pb(a[1]);
			string sss = "1 1";
			ans.pb(sss);
			while(l <= m) {
				while(a[l] != st.front()) {
					string s = "1 1"; ans.pb(s); 
					if(a[l] == st.back()) st.pop_back(),l ++;
					else st.push_back(a[l]), l ++;
				}
				string s = "1 2"; ans.pb(s);
				s = "2 1 2"; ans.pb(s);
				st.pop_front();
				l ++;
			}
			cout << ans.size() << endl;
			for(auto s:ans) cout << s << endl;
		}
	}
	else if(t % 10 == 3) {
		while(t --) {
			flag = false;
			n = read(), m = read(), k = read();
			for(int i = 1; i <= m; i ++) a[i] = read();
			dfs(1);
		}
	}
	else {
		while(t --) {
			flag = false;
			n = read(), m = read(), k = read();
			for(int i = 1; i <= m; i ++) a[i] = read();
			dfss(1);
		}
	}
}
