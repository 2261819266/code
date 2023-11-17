#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
#define ll long long 
#define int ll

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::max;

struct Trie {
#define word (i - 'a')
#define pw a[p][word]
	vector<vector<int>> a;
	vector<int> v;
	static const int root = 1;
	vector<int> New() const { return vector<int>(26, 0); }
	
	Trie() {
		a.assign(root + 1, New());
		v.assign(root + 1, -5);
	}
	
	void insert(const string &s, int x) {
		int p = root;
		for (int i : s) {
			if (!pw) {
				pw = a.size();
				a.push_back(New());
				v.push_back(-5);
			}
			p = pw;
		}
		v[p] = x;
	}
	
	int find(const string &s) const {
		int p = root;
		for (int i : s) {
			if (!pw) return -5;
			p = pw;
		}
		return v[p];
	}
	
	int operator[](const string &s) const { return find(s); }
} mp;

struct Node {
	vector<int> a; 
	ll size;
	string name;
	int dui;
	Trie NT, Nid;
	vector<int> di;
	vector<string> names;
	void push(int x) {
		a.push_back(x);
	}
	
	void insert(int type, const string s) {
		NT.insert(s, type);
	}
	
	ll &operator*() {
		return size;
	}
};

struct Var {
	int type;
	string name;
	ll di;
};

Trie vars;

vector<Node> a;
vector<Var> b;

void Struct() {
	int n;
	cin >> n;
	mp.insert("byte", 0);
	mp.insert("short", 1);
	mp.insert("int", 2);
	mp.insert("long", 3);
	a.push_back({vector<int>(), 1, "byte", 1});
	a.push_back({vector<int>(), 2, "short", 2});
	a.push_back({vector<int>(), 4, "int", 4});
	a.push_back({vector<int>(), 8, "long", 8});
	while(n--) {
		int op;
		cin >> op;
		if (op == 1) {
			Node x = {};
			int m;
			cin >> x.name >> m;
			mp.insert(x.name, a.size());
			for (int I = 0; I < m; I++) {
				string u, v;
				cin >> u >> v;
				x.push(mp[u]);
				x.insert(mp[u], v);
				x.Nid.insert(v, I);
				x.dui = max(x.dui, a[mp[u]].dui);
				x.names.push_back(v);
			}
			ll d = 0;
			for (int i : x.a) {
				ll ts = a[i].dui;
				ll e = d % ts;
				if (e) d += ts - e;
				x.di.push_back(d);
				d += a[i].size;
			}
			ll e = d % x.dui;
			if (e > 0) d += x.dui - e;
			x.size = d;
			a.push_back(x);
			cout << x.size << " " << x.dui << "\n";
//			cerr << n << "\n";
		} else if (op == 2) {
			string u, v;
			cin >> u >> v;
			vars.insert(v, b.size());
			if (b.empty()) b.push_back({mp[u], v, 0});
			else {
				Var la = b.back();
				ll d = la.di + a[la.type].size;
				ll N = a[mp[u]].dui;
				ll e = d % N;
				if (e > 0) d += N - e;
				b.push_back({mp[u], v, d});
			}
			cout << b.back().di << "\n";
		} else if (op == 3) {
			string u;
			cin >> u;
			vector<int> point;
			point.push_back(-1);
			for (int i = 0; i < (int)u.size(); i++) {
				if (u[i] == '.') point.push_back(i);
			}
			point.push_back(u.size());
			int d = 0;
			int now = 0;
			for (int i = 1; i < (int)point.size(); i++) {
//				cerr << 1;
				string v(u.begin() + point[i - 1] + 1, u.begin() + point[i]);
//				cerr << v << "\n";
				if (i == 1) {
					d = b[vars[v]].di;
					now = b[vars[v]].type;
				} else {
//					cerr << 1;
					d += a[now].di[a[now].Nid[v]];
					now = a[now].NT[v];
				}
//				cerr << d << " " << now << "\n";
//				cerr << 2;
			}
			cout << d << "\n";
		} else {
			ll x;
			cin >> x;
//			cerr << b.back().di;
			
			if (b.empty() || x > b.back().di + a[b.back().type].size) {
				cout << "ERR\n";
				continue;
			}
			int d = 0, now = b[0].type;
			string s;
			
			for (int i = 1; i < (ll)b.size(); i++) {
				if (b[i].di > x) {
					now = b[i - 1].type;
					d = b[i - 1].di;
					s += b[i - 1].name;
					break;
				}
			}
			if (!s.size()) now = b[0].type, s += b[0].name;
//			int dd = d, nnow = now;
			for(int t = 0; t < 105; t++) {
				if (d == x) {
					cout << s << "\n";
					break;
				}
//				cerr << d << " " << now << "\n";
				if (now < 4 && d + a[now].size >= x) {
					cout << s << "\n";
					break;
				}
				
				// if (t > 100) {
				// 	cout << "ERR\n";
				// 	break;
				// }
				
				for (int i = 0; i < (ll)a[now].di.size(); i++) {		
					if (d + a[now].di[i] + a[a[now].a[i]].size > x) {
						s += "." + a[now].names[i];
						d += a[now].di[i];
						now = a[now].a[i];
//						s += "." + a[now].name;
						break;
					}
				}
			}
		}
	}
}

signed main() {
	// fo(struct)
	Struct();
	return 0;
}


